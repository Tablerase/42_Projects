/**
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 */

/**
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
  Input: x = 121
  Output: true
  Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
  Input: x = -121
  Output: false
  Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:
  Input: x = 10
  Output: false
  Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int num = x;
    int digit = 0;
    long reversed = 0;
    // extract last digit
    while (num > 9) {
      digit = num % 10;
      // append to reversed num
      reversed = reversed * 10 + digit;
      num = num / 10;
    }
    reversed = reversed * 10 + num;
    if (x == reversed) {
      return true;
    }
    return false;
  }
};

void Test(int x) {
  Solution exo = Solution();
  std::clog << "x = " << x << " palindrome: " << std::boolalpha
            << exo.isPalindrome(x) << '\n';
}

int main(int argc, char *argv[]) {
  Test(121);
  Test(-121);
  Test(10);
  Test(1534236469);
  return 0;
}
