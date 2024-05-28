# Algorithms

An algorithm is a sequence of steps that is used to solve a problem. Algorithms are used to perform specific tasks, such as searching, sorting, and counting.

## Find

The `std::find` algorithm is used to search for an element in a container.

```cpp
std::container_type::iterator it = std::find(container.begin(), container.end(), value);
```

Returns an iterator to the first element in the range [first, last) that compares equal to value. If no such element is found, the function returns last.

```cpp
#include <algorithm>

int main()
{
  std::vector<int> vector{1, 2, 3};
  std::vector<int>::iterator it = std::find(vector.begin(), vector.end(), 2);
  if (it != vector.end())
  {
    std::cout << "Element found\n";
  }
  return (0);
}

// Output: Element found
```

## Difference

### std::adjacent_difference

The `std::adjacent_difference` algorithm is used to compute the differences between adjacent elements in a container.

```cpp
#include <algorithm>

int main()
{
  std::vector<int> vector{1, 2, 3};
  std::vector<int> result(vector.size());
  std::adjacent_difference(vector.begin(), vector.end(), result.begin());
  for (int x : result)
  {
    std::cout << x << "\n";
  }
  return (0);
}

// Output: 1 1 1
```

## For Each

The `std::for_each` algorithm is used to apply a function to each element in a container.

```cpp
#include <algorithm>
#include <vector>

void print(int x)
{
  std::cout << x << "\n";
}

int main()
{
  std::vector<int> vector{1, 2, 3};
  std::for_each(vector.begin(), vector.end(), print);
  return (0);
}
```
