#include <iostream>
/**
 * watchexec --exts cpp "g++ file.cpp && ./a.out"
 */

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if (k == 2 || k == 5) {
      return -1;
    }

    int32_t remainder = 0;
    for (int length = 1; length <= k; length++) {
      remainder = (remainder * 10 + 1) % k;
      if (remainder == 0) {
        return length;
      }
    }
    return -1;
  }
};

void test(int k, int expected) {
  Solution sol;
  int result = sol.smallestRepunitDivByK(k);
  if (result == expected) {
    std::cout << "Test passed for k = " << k << std::endl;
  } else {
    std::cout << "Test failed for k = " << k << ". Expected: " << expected
              << ", Got: " << result << std::endl;
  }
}

int main() {
  test(1, 1);
  test(2, -1);
  test(3, 3);
  test(19, 18);
}
