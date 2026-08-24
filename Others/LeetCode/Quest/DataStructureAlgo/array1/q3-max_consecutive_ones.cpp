/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/**
*
Given a binary array nums, return the maximum number of consecutive 1's in the
array.
*/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int max_ones = 0;
    int current_count = 0;

    for (const int value : nums) {
      if (value == 1) {
        current_count++;
      } else {
        if (current_count > max_ones) {
          max_ones = current_count;
        }
        current_count = 0;
      }
    }

    if (current_count > max_ones) {
      max_ones = current_count;
    }

    return max_ones;
  }
};

void test(vector<int> nums, int expected) {
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  std::cout << "Nums: \n";
  for (const int value : nums) {
    std::cout << value << ",";
  }
  std::cout << "\n";
  Solution s = Solution();
  std::cout << "Result: " << s.findMaxConsecutiveOnes(nums)
            << " , Expected: " << expected;
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  test({1, 1, 0, 1, 1, 1}, 3);
  test({1, 0, 1, 1, 0, 1}, 2);
  return 0;
}
