#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

// Chain List for Clients data
typedef struct s_client_fd{
  int fd;
  int id;
  struct s_client_fd * next;
} t_client_fd;

t_client_fd * client_list = NULL;

// Global variables

int g_id = 0;
int g_server_socket;

#define BUFFER_SIZE 1000000
char buffer[BUFFER_SIZE];

fd_set storefds, readfds, writefds;

// Functions

void fatal_error(){
  write(2, "Fatal error\n", strlen("Fatal error\n"));
  close(g_server_socket);
  exit(1);
}

int get_max_fd(){
  t_client_fd * tmp = client_list;

  int max_fd = g_server_socket;
  while (tmp)
  {
    if (tmp->fd > max_fd) {
      max_fd = tmp->fd;
    }
    tmp = tmp->next;
  }
  return max_fd;
}

int get_id(int fd_to_search){
  t_client_fd * tmp = client_list;
  
  while (tmp)
  {
    if (tmp->fd == fd_to_search){
      return tmp->id;
    }
    tmp = tmp->next;
  }
  return -1;
}

void send_to_all(char *to_send, int except_fd){
  t_client_fd * tmp = client_list;

  for (; tmp != NULL; tmp = tmp->next){ 
    if (FD_ISSET(tmp->fd, &writefds) && tmp->fd != except_fd){
      int send_return = send(tmp->fd, to_send, strlen(to_send), 0);
      if (send_return == -1){
        #ifdef LOG
        perror("send()");
        #endif
      } else {
        #ifdef LOG
        printf("Server info: %s | %d bytes send\n", buffer, send_return);
        #endif
      }
    }
  }
}

void add_client(){
  // Creating client address
  struct sockaddr_in addr_client;
  socklen_t addr_len = sizeof(addr_client);
  int client_fd = accept(g_server_socket, (struct sockaddr *)&addr_client, &addr_len);
  if (client_fd == -1){
    #ifdef LOG
    perror("accept()");
    #endif
    fatal_error();
  }
  t_client_fd * new = malloc(sizeof(t_client_fd));
  if (new == NULL){
    #ifdef LOG
    perror("malloc()");
    #endif
    fatal_error();
  }

  // Send to all
  bzero(&buffer, BUFFER_SIZE);
  sprintf(buffer, "server: client %d just arrived\n", g_id);
  send_to_all(buffer, g_server_socket);
  bzero(&buffer, BUFFER_SIZE);

  // Add to client list and set
  FD_SET(client_fd, &storefds);
  new->id = g_id++;
  new->fd = client_fd;
  new->next = NULL;
  if (client_list == NULL){
    client_list = new;
  } else {
    t_client_fd * tmp = client_list;
    while(tmp->next)
    {
      tmp = tmp->next;
    }
    tmp->next = new;
  }
}

void rm_client(int fd_to_rm){
  // Send disconnect msg to all clients
  bzero(&buffer, BUFFER_SIZE);
  sprintf(buffer, "server: client %d just left\n", get_id(fd_to_rm));
  send_to_all(buffer, fd_to_rm);
  bzero(&buffer, BUFFER_SIZE);
  // Find client to remove
  t_client_fd * rm_client = NULL;
  if (client_list && client_list->fd == fd_to_rm){
    rm_client = client_list;
    client_list = client_list->next;
  } else {
    t_client_fd * tmp = client_list;
    while (tmp && tmp->next && tmp->next->fd != fd_to_rm)
      tmp = tmp->next;
    if (tmp && tmp->next && tmp->next->fd == fd_to_rm){
      rm_client = tmp->next;
      tmp->next = tmp->next->next;
    }
  }
  // Remove client
  if (rm_client){
    free(rm_client);
    FD_CLR(fd_to_rm, &storefds);
    close(fd_to_rm);
  } else {
    #ifdef LOG
    printf("Invalid fd to rm\n");
    #endif
  }
}

void extract_msg(int except_fd){
  char msg_buffer[BUFFER_SIZE + 64];
  bzero(&msg_buffer, BUFFER_SIZE + 64);

  sprintf(msg_buffer, "client %d: %s", get_id(except_fd), buffer);
  send_to_all(msg_buffer, except_fd);
  bzero(&buffer, BUFFER_SIZE);
}

int main(int ac, char **av) {
  // Check amount of arguments
  if (ac != 2){
    write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
    return EXIT_FAILURE;
  }

  // socket create and verification 
  g_server_socket = socket(AF_INET, SOCK_STREAM, 0); 
  if (g_server_socket == -1) {
    #ifdef LOG
    perror("socket()");
    #endif
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
  } else {
    #ifdef LOG
    perror("Socket()");
    #endif
  }

  // assign IP, PORT
  struct sockaddr_in servaddr;
  bzero(&servaddr, sizeof(servaddr));

  int port = atoi(av[1]);
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
  servaddr.sin_port = htons(port); 
  
  // Binding newly created socket to given IP and verification 
  if ((bind(g_server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
    #ifdef LOG
    perror("bind()");
    #endif
    fatal_error();
  } else {
    #ifdef LOG
    perror("Bind()");
    #endif
  }
  // Listening to incomming traffic
  if (listen(g_server_socket, 100) != 0) {
    #ifdef LOG
    perror("listen()");
    #endif
    fatal_error();
  } else {
    #ifdef LOG
    perror("listen()");
    #endif
  }
  // Init fds set;
  FD_ZERO(&storefds);
  FD_SET(g_server_socket, &storefds);
  bzero(&buffer, BUFFER_SIZE);
  // Server Loop
  while (1)
  {
    // Update fds sets
    readfds = writefds = storefds;
    if (select(get_max_fd() + 1, &readfds, &writefds, NULL, NULL) == -1){
      #ifdef LOG
      perror("select()");
      #endif
      continue;
    }

    // Read ready fds
    for (int fd = 0; fd <= get_max_fd(); fd++){
      if (FD_ISSET(fd, &readfds) != 0){
        // Add new client (server socket read ready == incomming request
        if (fd == g_server_socket){
          add_client();
          break;
        }
        // Receive msg
        int data_received = 1;
        while (data_received == 1 && buffer[strlen(buffer) - 1] != '\n')
        {
          // Read byte by byte to ensure disconnect and jumpline detection
          data_received = recv(fd, buffer + strlen(buffer), 1, 0);
          if (data_received == 0)
            break;
        }
        // Disconnection handler
        if (data_received <= 0){
          rm_client(fd);
          break;
        }
        // Extract_msg_from_buffer
        extract_msg(fd);
      }
    }
  }

  return EXIT_SUCCESS;
}