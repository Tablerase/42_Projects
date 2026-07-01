#include <iomanip>
#include <iostream>
#include <vector>

/**
 * watchexec --exts cpp "g++ file.cpp && ./a.out"
 */

/**
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0,
and 128 % 8 == 0. A self-dividing number is not allowed to contain the digit
zero.

Given two integers left and right, return a list of all the self-dividing
numbers in the range [left, right] (both inclusive).

Example 1:
  Input: left = 1, right = 22
  Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
Example 2:
  Input: left = 47, right = 85
  Output: [48,55,66,77]
*/

class Solution {
public:
  bool canSelfDivide(const int x) {
    int temp_x = x;
    int to_check = 0;
    while (temp_x != 0) {
      to_check = temp_x % 10;
      temp_x = temp_x / 10;
      if (to_check == 0 || x % to_check != 0) {
        // std::cout << "Fail with : " << x << " and div by: " << to_check <<
        // '\n';
        return false;
      }
    }
    return true;
  }

  std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> res;
    for (int index = left; index <= right; index++) {
      // check for self divisible
      if (!canSelfDivide(index)) {
        continue;
      }
      res.push_back(index);
    }
    return res;
  }
};

void test(int left, int right, std::vector<int> expected) {
  Solution s = Solution();
  std::cout << std::setfill('=') << std::setw(40) << '\n';
  std::cout << "Left: " << left << " Right: " << right << "\nResult: \n";
  std::vector<int> res = s.selfDividingNumbers(left, right);
  for (const int element : res) {
    std::cout << element << '|';
  }
  std::cout << "\nExpected: " << '\n';
  for (const int element : expected) {
    std::cout << element << '|';
  }
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> test1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  test(1, 22, test1);
  test(47, 85, {48, 55, 66, 77});
}
