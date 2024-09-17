#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_fdclient {
  int fd;
  int id;
  struct s_fdclient * next;
} t_fdclient;

t_fdclient * clients = NULL;
fd_set currentset, readset, writeset;

int g_id = 0;
int g_server_socket;

// 4 bytes buffer (avoid many memory operations)
#define BUFFER_SIZE 4096
char buffer[BUFFER_SIZE];

////////////////////////////////////////////////////////////////////////////

void fatal(){
  char *msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  close(g_server_socket);
  exit(EXIT_FAILURE);
}

int get_max_fd(){
  t_fdclient *tmp;
  tmp = clients;
  int max_fd = g_server_socket;
  while(tmp){
    if (tmp->fd > max_fd) 
      max_fd = tmp->fd;
    tmp = tmp->next;
  }
  return max_fd;
}

int get_id(int fd){
  t_fdclient * tmp;
  tmp = clients;
  while (tmp) {
    if (tmp->fd == fd){
      return tmp->id;
    }
    tmp = tmp->next;
  }
  return -1;
}

void send_to_all(int except_fd){
  t_fdclient * tmp = clients;
  int result = 0;
  while(tmp)
  {
    if (tmp->fd != except_fd && FD_ISSET(tmp->fd, &writeset)){
      result = send(tmp->fd, &buffer, strlen(buffer), 0);
      if ( result == -1){
        #ifdef LOG
        perror("send()");  
        #endif /* ifdef LOG */
        fatal();
      } else {
        #ifdef LOG
        printf("Server send \"%s\" of %d bytes\n", buffer, result);
        #endif /* ifdef LOG */
      };
    }
    tmp = tmp->next;
  }
}

void add_client(){
  t_fdclient * tmp;
  tmp = clients;

  struct sockaddr_in address;
  socklen_t address_len = sizeof(address);
  int client_fd = accept(g_server_socket, (struct sockaddr *) &address, &address_len); 
  if (client_fd == -1){
    #ifdef LOG
    perror("client accept()"); 
    #endif /* ifdef LOG */
    fatal();
  }
  
  // Send new connections msg to all
  // clear buffer
  bzero(&buffer, sizeof(buffer));
  sprintf(buffer, "server: client %d just arrived\n", g_id);
  #ifdef LOG
  printf("Server client %d is connected.\n", g_id);
  #endif /* ifdef LOG */
  send_to_all(client_fd);

  // Add to fd set
  FD_SET(client_fd, &currentset);
  // Add to list
  t_fdclient *new;
  new = malloc(sizeof(t_fdclient));
  if (new == NULL){
    #ifdef LOG
    perror("malloc client()"); 
    #endif /* ifdef LOG */
    fatal();
  }
  new->next = NULL;
  new->id = g_id;
  g_id++;
  new->fd = client_fd;
  if (clients == NULL){
    clients = new;
  } else {
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = new;
  }
}

void rm_client(int fd_to_rm){
  // Send disconnection msg to all
  bzero(&buffer, sizeof(buffer));
  sprintf(buffer, "server: client %d just left\n", get_id(fd_to_rm));
  send_to_all(fd_to_rm);
  // Remove and clean disconnected client
  t_fdclient * tmp = clients;
  t_fdclient * to_rm = NULL;
  if (clients && clients->fd == fd_to_rm){
    to_rm = clients;
    clients = tmp->next;
  } else {
    while (tmp && tmp->next && tmp->next->fd != fd_to_rm)
      tmp = tmp->next;
    if (tmp && tmp->next && tmp->next->fd == fd_to_rm){
      to_rm = tmp->next;
      tmp->next = tmp->next->next;
    }
  }
  if (to_rm)
    free(to_rm);
  FD_CLR(fd_to_rm, &currentset);
  close(fd_to_rm);
}

void extract_msg(int fd){

}

int main(int ac, char **av) {
  // Check input
  if (ac != 2){
    write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
    return EXIT_FAILURE;
  }

	// socket create and verification 
	g_server_socket = socket(AF_INET, SOCK_STREAM, 0); 
	if (g_server_socket == -1) { 
    #ifdef LOG
    perror("socket()");
    #endif /* ifdef LOG */
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    return EXIT_FAILURE;
	} 
	else {
    #ifdef LOG
		printf("Socket successfully created..\n"); 
    #endif /* ifdef LOG */
  }

	struct sockaddr_in servaddr; 
	bzero(&servaddr, sizeof(servaddr)); 
	// assign IP, PORT 
  int port = atoi(av[1]);
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(g_server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		#ifdef LOG
    perror("bind()");
    #endif
    fatal();
	} else {
    #ifdef LOG
    perror("server socket bind()");
    #endif
  }
  // Listen to incomming connections
	if (listen(g_server_socket, 100) != 0) {
    #ifdef LOG
    perror("listen()");
    #endif
    fatal();
	}

  // Init FD sets
  FD_ZERO(&currentset);
  FD_SET(g_server_socket, &currentset);
  bzero(&buffer, sizeof(buffer));

  // Server Loop
  while(1){
    // Update sets
    readset = writeset = currentset;
    int result_select = select(get_max_fd() + 1, &readset, &writeset, NULL, NULL);
    if ( result_select == -1){
      #ifdef LOG
      perror("select()");
      #endif /* ifdef LOG */
      continue;
    }

    // FD management
    for (int fd = 0; fd <= get_max_fd(); fd++){
      // Ready to read fds
      if (FD_ISSET(fd, &readset)){
        // Add new client (server socket read ready == incomming request)
        if (fd == g_server_socket){
          add_client();
          break;
        }
        // Receved msgs
        int received_size = recv(fd, buffer, BUFFER_SIZE, 0);
          // Check for disconnect
        if (received_size <= 0){
          rm_client(fd);
          break;
        }
          // TODO: Extract msg
        extract_msg(fd);
      }
    }

  }
  
  return EXIT_SUCCESS;
}
