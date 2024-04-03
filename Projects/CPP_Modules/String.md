# Strings

A string is a sequence of characters. Strings are used to represent text in a program.

- C-style strings are arrays of characters that are terminated by a null character (`\0`).

```cpp
char s[] = "Hello, world!";
```

- C++ strings are objects that are used to represent text. C++ strings are part of the standard library and provide more functionality than C-style strings.

```cpp
std::string s = "Hello, world!";
```

*Best practice*: Use C++ strings instead of C-style strings whenever possible.

## std::string

The `std::string` class is a class type that is used to represent text in a program. The `std::string` class is part of the standard library (in the string header) and provides a wide range of functionality for working with strings.

```cpp
#include <string>

int main()
{
  std::string s { "Hello, world!" };
  return (0);
}
```

- The `std::string` class is a class template that is used to create string objects.
- The `std::string` class is part of the `std` namespace, so it is accessed using the scope resolution operator (`::`).

Cost of using `std::string`:
- Avoid copying `std::string` objects unnecessarily.
- It is expensive to use `std::string` for small strings because it dynamically allocates memory on the heap.
  - For small strings, it is better to use C-style strings or `std::string_view`.

```cpp
#include <iostream>
#include <string>

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer
    printString(s);

    return 0;
}
```

### [std::string_view (C++17)](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/)

`std::string_view` is a lightweight object that is used to represent a view of a string. It does not own the string data, so it is more efficient than `std::string` for small strings.

It recommended to use `std::string_view` instead of `std::string` when you need to pass a string to a function that does not need to modify the string. **Read-only** functions should take `std::string_view` parameters.

```cpp
#include <iostream>
#include <string_view> // C++17

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}
```

## String Literals

A string literal is a sequence of characters enclosed in double quotes. String literals are used to represent text in a program.

```cpp
std::string s { "Hello, world!" };
```

## String input

The `std::getline` function is used to read a line of text from the console.

```cpp
#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::getline(std::cin >> std::ws, s);
  std::cout << "You entered: " << s << "\n";
  return (0);
}
```

- The `std::cin` is not used to read strings directly because it stops reading at the first whitespace character.
- The `std::ws` manipulator is used to skip leading whitespace characters.
  - 'ws' stands for whitespace.
  - `space`, `tab`, `newline`, `carriage return`, `vertical tab`, `form feed`.

## String Length

The `length` function is used to get the length of a string. The length of a string is the number of characters in the string. The length of a string does not include the null character (`\0`).
  - The `size` function can also be used to get the length of a string.
  - lenght is a member function of the `std::string` class.

```cpp
#include <iostream>
#include <string>

int main()
{
  std::string s { "Hello, world!" };
  std::cout << s.length() << "\n"; // Output: 13
  return (0);
}
```

## String Class

🔗 [List of String - functions](https://cplusplus.com/reference/string/string/)

<table>
  <tbody>
    <tr>
      <th>Function</th>
      <th>Effect</th>
    </tr>
    <tr>
        <td colspan="2"><center><b>Creation and destruction</b></center>
      </td>
    </tr>
    <tr>
      <td><a href="https://www.learncpp.com/cpp-tutorial/17-2-ststring-construction-and-destruction/">(constructor)</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-2-ststring-construction-and-destruction/">(destructor)</a></td>
      <td>Create or copy a string<br>Destroy a string</td>
    </tr>
    <tr>
      <td colspan="2"><center><b>Size and capacity</b></center></td>
    </tr>
    <tr>
      <td nowrap=""><a href="https://www.learncpp.com/cpp-tutorial/17-3-stdstring-length-and-capacity/">capacity()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-3-stdstring-length-and-capacity/">empty()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-3-stdstring-length-and-capacity/">length(), size()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-3-stdstring-length-and-capacity/">max_size()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-3-stdstring-length-and-capacity/">reserve()</a></td>
      <td nowrap="">Returns the number of characters that can be held without reallocation<br>Returns a boolean indicating whether the string is empty<br>Returns the number of characters in string<br>Returns the maximum string size that can be allocated<br>Expand or shrink the capacity of the string</td>
    </tr>
    <tr>
      <td colspan="2"><center><b>Element access</b></center></td></tr><tr><td nowrap=""><a href="https://www.learncpp.com/cpp-tutorial/17-4-stdstring-character-access-and-conversion-to-c-style-arrays/">[], at()</a></td><td nowrap="">Accesses the character at a particular index</td></tr><tr><td colspan="2"><center><b>Modification</b></center></td></tr><tr><td nowrap=""><a href="https://www.learncpp.com/cpp-programming/17-5-stdstring-assignment-and-swapping/">=, assign()</a><br><a href="https://www.learncpp.com/uncategorized/17-6-stdstring-appending/">+=, append(), push_back()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-7-stdstring-inserting/">insert()</a><br>clear()<br>erase()<br>replace()<br>resize()<br><a href="https://www.learncpp.com/cpp-programming/17-5-stdstring-assignment-and-swapping/">swap()</a></td>
      <td nowrap="">Assigns a new value to the string<br>Concatenates characters to end of the string<br>Inserts characters at an arbitrary index in string<br>Delete all characters in the string<br>Erase characters at an arbitrary index in string<br>Replace characters at an arbitrary index with other characters<br>Expand or shrink the string (truncates or adds characters at end of string)<br>Swaps the value of two strings</td>
    </tr>
    <tr>
      <td colspan="2"><center><b>Input and Output</b></center></td>
    </tr>
    <tr>
      <td nowrap="">&gt;&gt;, getline()<br>&lt;&lt;<br><a href="https://www.learncpp.com/cpp-tutorial/17-4-stdstring-character-access-and-conversion-to-c-style-arrays/">c_str()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-4-stdstring-character-access-and-conversion-to-c-style-arrays/">copy()</a><br><a href="https://www.learncpp.com/cpp-tutorial/17-4-stdstring-character-access-and-conversion-to-c-style-arrays/">data()</a></td><td nowrap="">Reads values from the input stream into the string<br>Writes string value to the output stream<br>Returns the contents of the string as a NULL-terminated C-style string<br>Copies contents (not NULL-terminated) to a character array<br>Same as c_str(). The non-const overload allows writing to the returned string.</td></tr><tr><td colspan="2"><center><b>String comparison</b></center></td>
    </tr>
    <tr>
      <td nowrap="">==, !=<br>&lt;, &lt;=, &gt; &gt;=<br>compare()</td>
      <td nowrap="">Compares whether two strings are equal/unequal (returns bool)<br>Compares whether two strings are less than / greater than each other (returns bool)<br>Compares whether two strings are equal/unequal (returns -1, 0, or 1)</td>
    </tr>
    <tr>
      <td colspan="2"><center><b>Substrings and concatenation</b></center></td></tr>
    <tr>
      <td nowrap="">+<br>substr()</td><td nowrap="">Concatenates two strings<br>Returns a substring</td></tr><tr><td colspan="2"><center><b>Searching</b></center></td>
    </tr>
    <tr>
      <td nowrap="">find()<br>find_first_of()<br>find_first_not_of()<br>find_last_of()<br>find_last_not_of()<br>rfind()</td>
      <td nowrap="">Find index of first character/substring<br>Find index of first character from a set of characters<br>Find index of first character not from a set of characters<br>Find index of last character from a set of characters<br>Find index of last character not from a set of characters<br>Find index of last character/substring<p></p></td>
    </tr>
    <tr>
      <td colspan="2"><center><b>Iterator and allocator support</b></center></td></tr><tr><td nowrap="">begin(), end()<br>get_allocator()<br>rbegin(), rend()</td>
      <td nowrap="">Forward-direction iterator support for beginning/end of string<br>Returns the allocator<br>Reverse-direction iterator support for beginning/end of string</td>
    </tr>
  </tbody>
</table>
