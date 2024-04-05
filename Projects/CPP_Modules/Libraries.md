# Libraries

## C++ Standard Library

## CCTYPE

The `cctype` header file provides functions for working with characters.
  - The functions in the `cctype` header file are used to check if a character is alphabetic, numeric, alphanumeric, whitespace, uppercase, or lowercase.

| Function Name | Description | Example |
| --- | --- | --- |
| `isalpha(int c)` | Checks if the passed character is alphabetic | `isalpha('a')` returns true |
| `isdigit(int c)` | Checks if the passed character is a digit | `isdigit('1')` returns true |
| `isalnum(int c)` | Checks if the passed character is alphanumeric | `isalnum('2')` returns true |
| `isspace(int c)` | Checks if the passed character is a whitespace character | `isspace(' ')` returns true |
| `isupper(int c)` | Checks if the passed character is uppercase | `isupper('A')` returns true |
| `islower(int c)` | Checks if the passed character is lowercase | `islower('a')` returns true |
| `toupper(int c)` | Converts the passed character to uppercase | `toupper('a')` returns 'A' |
| `tolower(int c)` | Converts the passed character to lowercase | `tolower('A')` returns 'a' |

## [IOMANIP]()

📚 [Documentation](https://cplusplus.com/reference/iomanip/)

🏗️ [Info with Example](https://www.geeksforgeeks.org/iomanip-in-cpp/)

The `iomanip` header file provides functions for formatting input and output.

<table>
  <thead>
    <tr>
      <th>Function Name</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>setiosflags</td>
      <td>Set format flags (function)</td>
    </tr>
    <tr>
      <td>resetiosflags</td>
      <td>Reset format flags (function)</td>
    </tr>
    <tr>
      <td>setbase</td>
      <td>Set basefield flag (function)</td>
    </tr>
    <tr>
      <td><a href="https://cplusplus.com/reference/iomanip/setfill/">setfill</td>
      <td>Set fill character (function)</td>
    </tr>
    <tr>
      <td><a href ="https://cplusplus.com/reference/iomanip/setw/">setw</td>
      <td>Set field width (function)</td>
    </tr>
    <tr>
      <td>setprecision</td>
      <td>Set decimal precision (function)</td>
    </tr>
    <tr>
      <td>get_money</td>
      <td>Get monetary value (function)</td>
    </tr>
    <tr>
      <td>put_money</td>
      <td>Put monetary value (function)</td>
    </tr>
    <tr>
      <td>get_time</td>
      <td>Get date and time (function)</td>
    </tr>
    <tr>
      <td>put_time</td>
      <td>Put date and time (function)</td>
    </tr>
  </tbody>
</table>

