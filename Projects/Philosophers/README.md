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

- Philosopher number starts at 1 to `number_of_philosophers`.
- Each philosopher should be a thread.
- Each philosopher has one fork.
- To eat, a philosopher needs to have two forks.
- Prevent philosophers from duplicating forks, protect the forks state
with a mutex for each of them.
- They should avoid dying.

- Log:
  - Log the following events:
    - `timestamp_in_ms X has taken a fork`
    - `timestamp_in_ms X is eating`
    - `timestamp_in_ms X is sleeping`
    - `timestamp_in_ms X is thinking`
    - `timestamp_in_ms X died`
  - X is the philosopher number.
  - The timestamp is the time in milliseconds from the start of the simulation.
  - The simulation should stop when a philosopher dies.

  - Logs messages should not mixe with each other.
  - Log message annoncing the death of a philosopher should wait more than 10ms before printing it.

## Resources

⏯️ [Unix Threads - CodeVault](https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&feature=shared)

## Notions

### Threads

```mermaid
graph TD
  classDef ressource fill:#2fa;
  classDef process fill:#fa1;
    subgraph Process
        Ressource1[Memory]:::ressource
        Ressource2[Files]:::ressource
        point(( )) --> A[Thread 1]
        point(( )) --> B[Thread 2]
        point(( )) --> C[Thread 3]
    end
    Process2:::process
    subgraph Process2
        Ressource3[Memory2]:::ressource
        Ressource4[Files2]:::ressource
        point2(( )) --> D[Thread 1]
        point2(( )) --> E[Thread 2]
    end
```

In computer science, a thread of execution is the smallest sequence of programmed instructions that can be managed independently by a scheduler, which is typically a part of the operating system. In many cases, a thread is a component of a process.

The multiple threads of a given process may be executed concurrently (via multithreading capabilities), sharing resources such as memory, while different processes do not share these resources. In particular, the threads of a process share its executable code and the values of its dynamically allocated variables and non-thread-local global variables at any given time.

The implementation of threads and processes differs between operating systems.

- Threads offer several advantages over processes, including
  -  Faster creation, termination, and context switching times due to sharing the same address space and resources.
  -  Simplified communication between threads within the same process.
  -  Improved resource utilization and efficiency in multithreaded applications.

Issues with threads include
  -  Difficulty in writing and debugging multithreaded applications.
  -  Increased complexity in managing shared resources

#### Race conditions

A race condition occurs when the behavior of a system depends on the relative timing of events, such as the order in which threads are scheduled. This can lead to unpredictable results and bugs that are difficult to reproduce.

Like for example, if two threads are trying to access the same shared resource, and one of them modifies the resource while the other is reading it, the result can be unpredictable.

#### Other issues

**Data Race**: This is a condition where two or more threads access shared data simultaneously and at least one of them modifies the data. This can lead to unpredictable results if not handled properly.

**Condition Variables**: These are synchronization primitives used in multithreaded programming. A condition variable allows one thread to signal to one or more other threads that a certain condition has changed (for example, data has been produced that the other threads can consume).

**Thread Synchronization**: This is a general term for techniques that ensure that threads correctly interact with each other and with shared data. This can involve mutexes, locks, semaphores, condition variables, and other techniques.


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

int main()
{
    printf("Hello\n");
    usleep(1000000);  // Sleep for 1 second
    printf("World\n");

    return 0;
}
```

In this example, the program will print "Hello", wait for 1 second, and then print "World".

</details>

### gettimeofday

```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
```

`timeval` structure:

```c
struct timeval
{
    time_t      tv_sec;     // Seconds
    suseconds_t tv_usec;    // Microseconds
};
```

- Gets the current time.

Parameters:

- `tv`: A pointer to a `timeval` structure that will be filled with the current time.
- `tz`: A pointer to a `timezone` structure that will be filled with the current timezone information.
  - This parameter is generally not used and can be set to `NULL`.

Return value:

- On success, `gettimeofday` returns 0.
- On error, it returns -1.

Info:

The `tv_sec` field represents the number of seconds elapsed since the Unix Epoch (00:00:00 UTC, January 1, 1970), and the `tv_usec` field represents the number of microseconds in the current second.

<details>
<summary>Example</summary>

```c
#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;

    gettimeofday(&tv, NULL);

    printf("Seconds: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);

    return 0;
}
```

In this example, the program will print the current time in seconds and microseconds.

</details>

### pthread_create

Compile and link with `-pthread`.

```c
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
```

- Creates a new thread.

Parameters:

- `thread`: A pointer to a `pthread_t` structure that will be filled with the thread ID.
- `attr`: A pointer to a `pthread_attr_t` structure that specifies the thread's attributes.
  - This parameter is generally not used and can be set to `NULL`.
- `start_routine`: A pointer to the function that will be executed by the new thread.
- `arg`: A pointer to the argument that will be passed to the `start_routine` function.

Return value:

- On success, `pthread_create` returns 0.
- On error, it returns a positive error number.

Info:

- You have to check the return value of `pthread_create` to ensure that the thread was created successfully.

<details>
<summary>Example</summary>

Simple example:
```c
#include <stdio.h>
#include <pthread.h>

void *print_message(void *ptr) {
    char *message = (char *)ptr;
    printf("%s\n", message);
    sleep(1);
    return NULL;
}

int main() {
    pthread_t thread;
    char *message = "Hello";

    pthread_create(&thread, NULL, print_message, (void *)message);

    pthread_join(thread, NULL);

    printf(", world!\n");

    return 0;
}
```

In this example, the program creates a new thread that prints "Hello, world!".

Multiple threads example:
```c
#include <stdio.h>
#include <pthread.h>

void* routine()
{
	printf("Hello from thread\n");
	sleep(5);
	printf("Goodbye from thread\n");
	return NULL;
}

int main() {
    struct timeval tv;

    gettimeofday(&tv, NULL);

    pthread_t thread;
	pthread_t thread2;
	pthread_create(&thread, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine, NULL);

	printf("Hello from main\n");
	sleep(6);
	printf("Goodbye from main\n");
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
```

In this example, the program creates two new threads that print "Hello from thread" and "Goodbye from thread" after 5 seconds. The main thread prints "Hello from main" and "Goodbye from main" after 6 seconds.

</details>

### pthread_join

```c
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);
```

- Suspends execution of the calling thread until the target thread finishes execution.

Parameters:

- `thread`: The thread ID of the target thread.
- `retval`: A pointer to a pointer that will be filled with the return value of the target thread.
  - This parameter is generally not used and can be set to `NULL`.

Return value:

- On success, `pthread_join` returns 0.
- On error, it returns a positive error number.
