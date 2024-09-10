# Miniserver

## C Functions

<details>
<summary>Write</summary>

```c
ssize_t write(int fd, const void *buf, size_t count);
```

Writes up to `count` bytes from the buffer starting at `buf` to the file referred to by the file descriptor `fd`.

Errors happen when the function returns `-1`. The global variable `errno` is set to indicate the error.

Example:

```c
#include <unistd.h>

int main(void)
{
    char *str = "Hello, World!\n";
    write(1, str, 14);
    return (0);
}
```

</details>

<details>
<summary>Close</summary>

```c
int close(int fd);
```

Closes the file descriptor `fd`.

Errors happen when the function returns `-1`. The global variable `errno` is set to indicate the error.

Example:

```c
#include <unistd.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    close(fd);
    return (0);
}
```

</details>

<details>
<summary>Select</summary>

```c
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
```

The `select()` function allows a program to monitor multiple file descriptors, waiting until one or more of the file descriptors become "ready" for some class of I/O operation.


