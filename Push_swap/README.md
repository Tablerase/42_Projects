# Push Swap

## Description

Data must be sorted.

You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

Sorting values is simple. To sort them the fastest way possible is less simple. Especially
because from one integers configuration to another, the most efficient sorting solution can
differ.

## Rules

- You have 2 stacks called a and b.
- At the beginning:
  - a contains a random number of either positive and/or negative numbers without
    any duplicates.
  - b is empty
- The goal is to sort in ascending order numbers into stack a.

- To do this you have the following operations at your disposal:
  - `sa` (`swap a`) :
    - swap the first 2 elements at the top of stack a. Do nothing if there
    is only one or no elements.
  - `sb` (`swap b`) :
    - swap the first 2 elements at the top of stack b. Do nothing if there
    is only one or no elements.
  - `ss` (`swap a` and `swap b`) :
    - do `sa` and `sb` at the same time.
  - `pa` (`push a`) :
    - take the first element at the top of b and put it at the top of a. Do
    nothing if b is empty.
  - `pb` (`push b`) :
    - take the first element at the top of a and put it at the top of b. Do
    nothing if a is empty.
  - `ra` (`rotate a`) :
    - shift up all elements of stack a by 1. The first element becomes
    the last one.
  - `rb` (`rotate b`) :
    - shift up all elements of stack b by 1. The first element becomes
    the last one.
  - `rr` (`rotate a` and `rotate b`) :
    - do `ra` and `rb` at the same time.
  - `rra` (`reverse rotate a`) :
    - shift down all elements of stack a by 1. The last element
    becomes the first one.
  - `rrb` (`reverse rotate b`) :
    - shift down all elements of stack b by 1. The last element
    becomes the first one.
  - `rrr` (`reverse rotate a` and `reverse rotate b`) :
    - do `rra` and `rrb` at the same
    time.

## Push Swap Program

| Item | Description |
| --- | --- |
| Program name | **push_swap** |
| Turn in files | Makefile, *.h, *.c |
| Makefile | `NAME`, `all`, `clean`, `fclean`, `re` |
| Arguments | stack a: A list of integers |
| External functs. | `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` and any equivalent you coded|
| Libft authorized | Yes |
| Description | Sort stacks with the lowest possible number of operations. |

You have to write a program named `push_swap` that takes as an argument the `stack a` formatted as a list of integers. The **first argument should be at the top of the stack** (be careful about the order).

The program must **display** the smallest **list of instructions** possible to sort the `stack
a`, the smallest number being at the top.

Instructions must be separated by a `\n` and nothing else.

The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by **your program will be
compared against a limit**: the maximum number of operations tolerated. If your
program either **displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0**.

If **no parameters** are specified, the program must **not display anything and give the prompt back**.

In **case of error**, it must display **"Error" followed by a ’\n’ on the standard error**.
Errors include for example: **some arguments aren’t integers**, **some arguments are bigger than an integer and/or there are duplicates**.

## Coding part

### Structure and functions

```mermaid
flowchart TD
  classDef valid stroke:#0f0
  classDef invalid stroke:#f00
  classDef neutral stroke:#00f
  classDef data stroke:#ff0
  A[push_swap] --> B[main]
  B --> Arguments

  subgraph Arguments
    argc:::data --> C
    argv:::data --> C
    C[ft_check_args]:::neutral
    C -.- |1|D[ft_isdigit]
    C -.- |2|E[ft_atoi]
    C -.- |3|F[ft_isint]
    C -.- |4|I[ft_isdup]
  end

  Arguments --> |YES| Initialization
  Arguments --> |NO| error[ft_error in stderror]:::invalid
  Arguments --> |None| NoParameters[??? What to prompt back ???]:::neutral
  NoParameters --> exit:::neutral
  error --> exit
  
  subgraph Initialization
    G[ft_init_stack]:::valid
    G -.- stack_a:::data
    G -.- stack_b:::data
  end

  subgraph Sorting
    J[ft_select_sort]:::neutral --> K[ft_sort]
  end

  

  Initialization --> Sorting

```
