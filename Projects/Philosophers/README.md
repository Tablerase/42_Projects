# Philosophers

## Description

<table>
<thead>
  <tr>
    <th>Item</th>
    <th colspan="2">Description</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>Program name</td>
    <td colspan="2"><strong>philo</strong></td>
  </tr>
  <tr>
    <td>Turn in files</td>
    <td colspan="2"><code>Makefile</code>, <code>*.h</code>, <code>*.c</code>, <strong>in dir <code>philo/</code></strong></td>
  </tr>
  <tr>
    <td>Makefile</td>
    <td colspan="2"><code>NAME</code>, <code>all</code>, <code>clean</code>, <code>fclean</code>, <code>re</code></td>
  </tr>
  <tr>
    <td rowspan="5">Arguments</td>
    <td>number_of_philosophers</td>
    <td>The number of philosophers and also the number
of forks.</td>
  </tr>
  <tr>
    <td>time_to_die (in milliseconds)</td>
    <td>If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.</td>
  </tr>
  <tr>
    <td>time_to_eat (in milliseconds)</td>
    <td>The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.</td>
  </tr>
  <tr>
    <td>time_to_sleep (in milliseconds)</td>
    <td>The time a philosopher will spend sleeping.</td>
  </tr>
  <tr>
    <td>[number_of_times_each_philosopher_must_eat] (optional argument)</td>
    <td>If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.</td>
  </tr>
  <tr>
    <td>External functs.</td>
    <td colspan="2">memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock</td>
  </tr>
  <tr>
    <td>Libft authorized</td>
    <td colspan="2">No</td>
  </tr>
  <tr>
    <td>Description</td>
    <td colspan="2">Philosophers with threads and mutexes</td>
  </tr>
</tbody>
</table>

- Each philosopher should be a thread.
- Each philosopher has one fork.
- To eat, a philosopher needs to have two forks.
- Prevent philosophers from duplicating forks, protect the forks state
with a mutex for each of them.
- They should avoid dying.

## Notions

### Threads

### Mutexes

### Semaphores (bonus)

## Functions

- `memset`: Sets a block of memory with a specified value. Used in C and C++.

- `printf`: Outputs formatted text to the console. Used in C and C++.

- `malloc`: Allocates a block of memory and returns a pointer to it. Used in C and C++.

- `free`: Deallocates a block of memory that was previously allocated by `malloc`, `calloc`, or `realloc`. Used in C and C++.

- `write`: Writes data from a buffer into a file or a file descriptor. Used in C and C++.

- `usleep`: Suspends execution of the calling thread for (at least) the number of microseconds specified. Used in Unix-like operating systems.

- `gettimeofday`: Gets the current time. Used in Unix-like operating systems.

- `pthread_create`: Creates a new thread. Used in POSIX threads (pthreads).

- `pthread_detach`: Marks a thread for deletion when it finishes execution. Used in pthreads.

- `pthread_join`: Suspends execution of the calling thread until the target thread finishes execution. Used in pthreads.

- `pthread_mutex_init`: Initializes a mutex. Used in pthreads.

- `pthread_mutex_destroy`: Destroys a mutex. Used in pthreads.

- `pthread_mutex_lock`: Locks a mutex. Used in pthreads.

- `pthread_mutex_unlock`: Unlocks a mutex. Used in pthreads.

### usleep

```c
#include <unistd.h>

int usleep(useconds_t usec);
```

- Suspends execution of the calling thread for (at least) the number of microseconds specified.

Parameters:

- `usec`: The number of microseconds to suspend execution.
  - `useconds_t` is an unsigned integer type.

Return value:

- On success, `usleep` returns 0.
- On error, it returns -1.

<details>
<summary>Example</summary>

```c
#include <unistd.h>

int main() {
    printf("Hello\n");
    usleep(1000000);  // Sleep for 1 second
    printf("World\n");

    return 0;
}
```
