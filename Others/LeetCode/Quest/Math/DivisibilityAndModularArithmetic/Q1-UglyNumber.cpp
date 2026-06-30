/**
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 */

/**
An ugly number is a positive integer which does not have a prime factor other
than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

Example 1:
  Input: n = 6
  Output: true
  Explanation: 6 = 2 × 3
Example 2:
  Input: n = 1
  Output: true
  Explanation: 1 has no prime factors.
Example 3:
  Input: n = 14
  Output: false
  Explanation: 14 is not ugly since it includes the prime factor 7.
*/
#include <iostream>

class Solution {
public:
  bool isUgly(int n) {
    // std::clog << "Leaf: " << n << '\n';

    // base case
    if (n <= 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }

    if (n % 2 == 0) {
      return isUgly(n / 2);
    }

    if (n % 3 == 0) {
      return isUgly(n / 3);
    }

    if (n % 5 == 0) {
      return isUgly(n / 5);
    }

    // dead end
    return false;
  }
};

void Test(int n) {
  Solution exo = Solution();
  std::clog << "Test " << n << std::boolalpha << ": " << '\n'
            << exo.isUgly(n) << '\n';
}

int main(int argc, char *argv[]) {
  Test(6);
  Test(1);
  Test(14);
  return 0;
}
