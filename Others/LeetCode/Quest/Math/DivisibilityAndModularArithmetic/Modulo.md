# Modulo Arithmetic and Divisibility

$$
A mod B = R
$$

$$
\frac{A}{B} = \textcolor{red}Q \text{ with remainder } \textcolor{green}R
$$
$$ \textcolor{red}Q \text{ is the Quotient}$$
$$ \textcolor{green}R \text{ is the Remainder}$$

## Cyclic Properties of Modulo

$$ \frac{0}{3} = 0 \text{ with remainder } 0$$
$$ \frac{1}{3} = 0 \text{ with remainder } 1$$
$$ \frac{2}{3} = 0 \text{ with remainder } 2$$
$$ \frac{3}{3} = 1 \text{ with remainder } 0$$
$$ \frac{4}{3} = 1 \text{ with remainder } 1$$
$$ ... $$

For modulo 3, the remainders cycle through $\textcolor{green}{0, 1, 2}$
as we increase the numerator. This cyclic property is fundamental in modular
arithmetic and is used in various applications, including cryptography,
computer science, and number theory.

### Comparison of Modulo Operations in Different Programming Languages

Python use pure mathematical modulo operation, which always returns a non-negative remainder.
In contrast, TypeScript (and JavaScript) uses a different approach where the sign of the result can be negative if the dividend is negative.

```python
# Python
-3 % 3  # Output: 0
-2 % 3  # Output: 1
-1 % 3  # Output: 2
0 % 3  # Output: 0
1 % 3  # Output: 1
2 % 3  # Output: 2
```

```ts
// TypeScript
-3 % 3 // Output: 0
-2 % 3 // Output: -2
-1 % 3 // Output: -1
0 % 3 // Output: 0
1 % 3 // Output: 1
2 % 3 // Output: 2
```
