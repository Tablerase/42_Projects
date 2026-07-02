# Combinatorics and Permutations

## Permutation formula

### Strict ordering

$$
P(\textcolor{blue}n, \textcolor{green}k) = \frac{\textcolor{blue}n!}{(\textcolor{blue}n - \textcolor{green}k)!}
$$
$$
\textcolor{green}k \text{ is the number of objects to choose from a set of } \textcolor{blue}n \text{ objects.}
$$
$$
\text{\textcolor{blue}n \text{ are unique objects, and the order of selection matters.}}
$$

#### Example

A teacher has 5 different books and wants to select 3 of them to display on a shelf. The order in which the books are displayed matters. How many different ways can the teacher select and arrange the books?

$$
Permutations = 5! = 5 \times 4 \times 3 \times 2 \times 1 = 120
$$
$$
\text{Ordered arrangements of 3 books from 5} = P(5, 3)
\\
P(5,3) = \frac{5!}{(5 - 3)!} = \frac{5!}{2!} = \frac{120}{2} = \bold{\textcolor{goldenrod}{60}}
$$

## Combination formula

### Order does not matter

$$
C(\textcolor{blue}n, \textcolor{green}k) = \frac{\textcolor{blue}n!}{\textcolor{green}k!(\textcolor{blue}n - \textcolor{green}k)!}
$$

#### Example

You have 5 different fruits and want to select 3 of them to make a fruit salad. The order in which you select the fruits does not matter. How many different combinations of fruits can you choose?

$$
C(5, 3) = \frac{5!}{3!(5 - 3)!} = \frac{5!}{3!2!} = \frac{120}{6 \times 2} = \frac{120}{12} = \bold{\textcolor{goldenrod}{10}}
$$
