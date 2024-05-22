# [Containers](https://learn.microsoft.com/en-us/cpp/standard-library/stl-containers?view=msvc-170)

📚 [Documentation](https://cplusplus.com/reference/stl/?kw=stl)

A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

Containers replicate structures very commonly used in programming:
- dynamic arrays (**vector**), 
- queues (**queue**), 
- stacks (**stack**), 
- heaps (**priority_queue**), 
- linked lists (**list**), 
- trees (**set**), 
- associative arrays (**map**)...

<table>
    <tr>
        <th>Type</th>
        <th>Container</th>
        <th>Description</th>
    </tr>
    <tr>
        <td rowspan="3">Sequence Containers</td>
        <td>std::vector</td>
        <td>Dynamic array that allows for fast access to elements and efficient additions/removals at the end.</td>
    </tr>
    <tr>
        <td>std::list</td>
        <td>Doubly-linked list that allows for efficient additions/removals at both ends.</td>
    </tr>
    <tr>
        <td>std::deque</td>
        <td>Double-ended queue that allows for efficient additions/removals at both ends and fast access to elements.</td>
    </tr>
    <tr>
        <td rowspan="2">Associative Containers</td>
        <td>std::map</td>
        <td>Sorted associative container that contains key-value pairs with unique keys.</td>
    </tr>
    <tr>
        <td>std::set</td>
        <td>Sorted associative container that contains unique elements.</td>
    </tr>
    <tr>
        <td rowspan="2">Unordered Associative Containers</td>
        <td>std::unordered_map</td>
        <td>Unsorted associative container that contains key-value pairs with unique keys, implemented using hash table.</td>
    </tr>
    <tr>
        <td>std::unordered_set</td>
        <td>Unsorted associative container that contains unique elements, implemented using hash table.</td>
    </tr>
    <tr>
        <td rowspan="3">Container Adaptors</td>
        <td>std::stack</td>
        <td>Adaptor for a container, which provides a LIFO (Last In First Out) data structure.</td>
    </tr>
    <tr>
        <td>std::queue</td>
        <td>Adaptor for a container, which provides a FIFO (First In First Out) data structure.</td>
    </tr>
    <tr>
        <td>std::priority_queue</td>
        <td>Adaptor for a container, which provides a priority queue where the element with the highest priority is always at the front.</td>
    </tr>
</table>

## Sequence Containers

Sequence containers maintain the ordering of inserted elements that you specify.

### [List](https://cplusplus.com/reference/list/list/)

Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as **doubly-linked lists**; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.
```cpp
#include <list>

int main()
{
  std::list<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  return (0);
}
```

## Vector

A vector is a container that is used to store a collection of elements. A vector is a sequence of elements that can be accessed in a specific order.

```cpp
#include <vector>

int main()
{
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  return (0);
}
```

## Associative Containers

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

### Map

A map is a container that is used to store key-value pairs. A map is a collection of elements that are stored in a specific order.

```cpp
#include <map>

int main()
{
  std::map<std::string, int> map;
  map["Alice"] = 30;
  map["Bob"] = 40;
  map["Charlie"] = 50;
  return (0);
}
```

## Iterators

An iterator is an object that is used to traverse a container. Iterators are used to access the elements of a container in a specific order.

```cpp
#include <list>

int main()
{
  std::list<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
  {
    std::cout << *it << "\n";
  }
  return (0);
}
```

## Algorithms

An algorithm is a sequence of steps that is used to solve a problem. Algorithms are used to perform specific tasks, such as searching, sorting, and counting.

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
