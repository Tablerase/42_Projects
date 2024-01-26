# Valgrind 🚱

## Valgrind GDB

Allow to debug with **`valgrind` and `gdb` simultaneously**. 

You can use this to **debug memory leaks in differents processes**. Or to debug a program that forks and execs another program. Its also useful to debug a program that uses threads. 

With this method you can debug the parent process and all its children and see step by step what they are doing with memory and where you are in the code with `gdb`.

### Setup

Flags :

```bash
valgrind --vgdb=yes --vgdb-error=0 <program> <arguments>
```

Recover the target from valgrind to send it to gdb

Then in another terminal :

```bash
gdb ./a.out
(gdb) set non-stop off
(gdb) target remote | vgdb
```

<details>
<summary> Demo </summary>

```bash
$ valgrind --vgdb=yes --vgdb-error=0 ./a.out
```

Data to recover from valgrind:

```bash
target remote | /usr/bin/vgdb --pid=286905
  --pid is optional if only one valgrind process is running
```

Then in another terminal :

`set non-stop off`: Ensure that GDB isn’t using non-stop mode (Valgrind doesn’t like that)

```bash
$ gdb ./a.out
(gdb) set non-stop off
(gdb) target remote | /usr/bin/vgdb --pid=286905
(gdb) break main
(gdb) continue
```

Then you can use gdb as usual. You can set breakpoints, step through the code, etc. That will display in valgrind what is happening with memory.

</details>

### Summary at position

Doing the leak check by sending a command to the ‘monitor’ (GDB lingo for the remote process).
This gives you an summary, exactly as at the end of any Valgrind-run, but at precisely this point in the execution. You can add various options to the command to get more out of it

```bash
(gdb) monitor leak_check
```