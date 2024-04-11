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

### Floating Point

<img src="https://engineering.fb.com/wp-content/uploads/2018/11/floating_point_4_darkcolor.006.png" title="Facebook engineering schema to represent traditionnal floating point">

- [Traditional Floating Point](http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
- [In AI - Meta](https://engineering.fb.com/2018/11/08/ai-research/floating-point-math/)

$$ \text{Floating Point} = \text{Sign} \times 2^{\text{Exponent}} \times \text{Fraction} $$

Floating point numbers are numbers that have fractional parts (usually expressed with a decimal point). They are used when the range of values is too large for an integer. Floating point numbers are used to represent real numbers (numbers that may have a fractional part).

Floating point numbers are stored in memory in a format that is different from the way integers are stored. Integers are stored in memory as a series of bits (binary digits), but floating point numbers are stored in a format that allows for a fractional part.

Floating point numbers are stored in memory using a format called IEEE 754. This format allows for a fractional part and an exponent part. The fractional part is stored as a series of bits, and the exponent part is stored as a series of bits. The exponent part is used to represent the power of 2 that the fractional part should be multiplied by.

Precision problem: to simplify things, the way we often think about loss of precision problems is that a float gradually gets "corrupted" as you do more and more operations on it.

#### Fixed Point

- [Fixed Point - Berkley](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)

<div style="display: flex; justify-content: space-between; margin: 10px;">
  <img src="https://www.researchgate.net/publication/353927374/figure/fig1/AS:1057456302080001@1629128637300/Example-of-fixed-point-number-representation.png" title="Fixed number example" width="50%" style="padding: 10px;">
  <img src="https://www.allaboutcircuits.com/uploads/thumbnails/round-26.gif" width="50%" title="Schema fixed point" style="padding: 10px;">
</div>

Fixed-point arithmetic is an arithmetic that represents numbers in a fixed number of digits. It is a way to represent numbers that have a fractional part without using floating-point numbers. Fixed-point arithmetic is used in situations where the range of values is too large for integers but the precision of floating-point numbers is not needed.

[Fixed Point in code - Geeks for Geeks](https://www.geeksforgeeks.org/fixed-point-representation/)

When an integer is shifted right by one bit in a binary system, it is comparable to being divided by two. Since we cannot represent a digit to the right of a binary point in the case of integers since there is no fractional portion, this shifting operation is an integer division.
-  A number is always divided by two when the bit pattern of the number is shifted to the right by one bit.
-  A number is multiplied by two when it is moved left one bit.

Advantages of Fixed Point Representation:

-  Integer representation and fixed point numbers are indeed close relatives.
-  Because of this, fixed point numbers can also be calculated using all the arithmetic operations a computer can perform on integers.
-  They are just as simple and effective as computer integer arithmetic.
-  To conduct real number arithmetic using fixed point format, we can reuse all the hardware designed for integer arithmetic.

Disadvantages of Fixed Point Representation:

-  Loss in range and precision when compared to representations of floating point numbers.



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
