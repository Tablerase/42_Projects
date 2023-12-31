# Computer Science

## Terms

### [Endianness](https://www.techopedia.com/definition/10180/endian)

- Endian or endianness is the byte order chosen for all digital computing made in a specific computer system and dictates the architecture and low-level programming approach to be used for that system. Though today, endianness is not such a large concern for system compatibility since it can always be circumvented in the lower levels so that high-level language programmers and users are already abstracted from the endianness of the system.
- Two endian:
  - Little Endian : the least significant bit (or "littlest" end) is first stored at address 0, and subsequent bits are stored incrementally.
  - Big Endian : opposite of Little Endian
  - ![Endian Difference](https://getkt.com/wp-content/uploads/2019/04/Endianness-Little-Endian-Big-Endian.jpg)

### [Bit Shifting / Bitwise Operation](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

Bit shifting is an operation done on all the bits of a binary value in which they are moved by a determined number of places to either the left or right. Bit shifting is used when the operand is being used as a series of bits rather than as a whole. In other words, the operand is treated as individual bits that stand for something and not as a value.

Bit shifting is often used in programming and has at least one variation in each programming language. Bit shifting may also be known as a bitwise operation.

1 byte = 8 bits = 256 values (0...255)

1 int = 4 bytes = 32 bits

   256    |    256    |    256    |    256    |
----------| --------- | --------- |---------- |
0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 |

```c
int red = 42;
```

   0    |    0    |    0    |    42    |
----------| --------- | --------- |---------- |
0000 0000 | 0000 0000 | 0000 0000 | **0010 1010** |

#### << : right shift

```c
red = red << 24;
// r = 704643072;
```

   red    |   none    |   none    |    none   |
--------- | --------- | --------- | --------- |
   42    |    0    |    0    |    0    |
**0010 1010** | 0000 0000 | 0000 0000 | 0000 0000 |

#### | : OR operator

```bitwise
0 0 0 1
0 0 1 1
    | |
0 0 1 1
```

Here's how it works:

- It takes two numbers as operands.
- It compares each bit of the first operand to the corresponding bit of the second operand.
- **If either bit is `1`, the corresponding result bit is set to `1`**. Otherwise, the corresponding result bit is `0`.

In the context of the code, `r << 24 | g << 16 | b << 8 | a` is used to combine the bits of the shifted values of `r`, `g`, `b`, and `a` into a single integer. Each color component occupies 8 bits in the `rgba` integer. The bitwise OR operation ensures that the bits from each color component are preserved in the correct location within the `rgba` integer.

```c
int rgba;     // 00000000 00000000 00000000 00000000
int r = 42;   // 00000000 00000000 00000000 00101010
int g = 100;  // 00000000 00000000 00000000 01100100
int b = 255;  // 00000000 00000000 00000000 11111111
int a = 255;  // 00000000 00000000 00000000 11111111
rgba = r << 24 | g << 16 | b << 8 | a; 
              // 00101010 01100100 11111111 11111111
printf("%i", rgba); 
// output: 711262207
```

   red    |   green    |   blue    |    alpha   |
--------- | --------- | --------- | --------- |
   42    |    100    |    255    |    255    |
0010 1010 | 0110 0100 | 1111 1111 | 1111 1111 |

#### >> : left  shift

#### & : AND operator

```bitwise
0 0 0 1
0 0 1 1
    | |
0 0 0 1
```

- & : takes two numbers as operands and does AND on every bit of two numbers. The result of AND is **1 only if both bits are 1**

```c
  printf("\n red = %i", rgba >> 24 & 0xFF);
  printf("\n green = %i", rgba >> 16 & 0xFF);
  printf("\n blue = %i", rgba >> 8 & 0xFF);
  printf("\n alpha = %i", rgba & 0xFF);

  
  // g =                  00000000 00000000 00000000 01100100 | = 100
  // g << 16 =            00000000 01100100                   | != 100 (100 before right shift)

  // rgba =               00101010 01100100 11111111 11111111 |
  // rgba >> 16 =                           00101010 01100100 | 11111111 11111111
  // 0xFF =               00000000 00000000 00000000 11111111 | = 255
  //   & : AND                                        ||  |  = only when 1 and 1 -> 1 else 0
  // rgba >> 16 & 0xFF =  00000000 00000000 00000000 01100100 = 100

  // output:
  // red = 42
  // green = 100
  // blue = 255
  // alpha = 25
```

#### ^ : XOR bitwise

```bitwise
0 0 0 1
0 0 1 1
    | |
0 0 1 0
```

The result of XOR is **1 if the two bits are different**.

#### ~ : NOT bitwise

```bitwise
0 0 1 1
| | | |
1 1 0 0
```

Takes **one number** and **inverts all bits** of it.

### [Complexity](https://victoria.dev/blog/a-coffee-break-introduction-to-time-complexity-of-algorithms/)

Complexity is a way to describe how an algorithm performs as the input size increases. It's a way to compare the efficiency of different approaches to a problem. It's also a way to describe how much time and memory an algorithm will require to run. There are two types of complexity:

- Time Complexity: Time taken by the algorithm to run as a function of the length of the input.
- Space Complexity: Space taken by the algorithm to run as a function of the length of the input.

The most common way to describe complexity is using Big $O$ notation. Big $O$ notation is a way to describe the upper bound of the complexity of an algorithm. It's a way to describe the worst-case scenario. It's also a way to describe the growth rate of the algorithm.

Let's look at some common sorting algorithms and their complexities:

- Bubble Sort:
  - Time Complexity: Best - $O(n)$, Average - $O(n^2)$, Worst - $O(n^2)$
  - Space Complexity: $O(1)$

- Selection Sort:
  - Time Complexity: Best - $O(n^2)$, Average - $O(n^2)$, Worst - $O(n^2)$
  - Space Complexity: $O(1)$

- Insertion Sort:
  - Time Complexity: Best - $O(n)$, Average - $O(n^2)$, Worst - $O(n^2)$
  - Space Complexity: $O(1)$

- Merge Sort:
  - Time Complexity: Best - $O(n log(n))$, Average - $O(n log(n))$, Worst - $O(n log(n))$
  - Space Complexity: $O(n)$

- Quick Sort:
  - Time Complexity: Best - $O(n log(n))$, Average - $O(n log(n))$, Worst - $O(n^2)$
  - Space Complexity: $O(log n)$

- Heap Sort:
  - Time Complexity: Best - $O(n log(n))$, Average - $O(n log(n))$, Worst - $O(n log(n))$
  - Space Complexity: $O(1)$

![Complexity](https://victoria.dev/blog/a-coffee-break-introduction-to-time-complexity-of-algorithms/graph.png)
