/**
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 */

/**

Given a signed 32-bit integer x, return x with its digits reversed. If reversing
x causes the value to go outside the signed 32-bit integer range [-231, 231 -
1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned)

123
-123
120
1534236469 => 0
-2147483648 => 0
*/
#include <cstdint>
#include <iostream>
#include <limits>

class Solution {
public:
  int reverse(int x) {
    int32_t max = std::numeric_limits<int32_t>::max();
    int32_t min = std::numeric_limits<int32_t>::min();
    if (x == max || x == min) {
      return 0;
    }

    int32_t reverse = 0;

    while (x != 0) {
      int32_t digit = x % 10;

      if (reverse > max / 10 || reverse < min / 10) {
        return 0;
      }
      reverse = reverse * 10 + digit;

      x = x / 10;
    }
    return reverse;
  }
};

void Test(int x) {
  Solution exo = Solution();
  std::clog << "x = " << x << " reversing: " << exo.reverse(x) << '\n';
}

int main(int argc, char *argv[]) {
  Test(123);
  Test(-123);
  Test(120);
  Test(1534236469);
  Test(-2147483648);
  return 0;
}
