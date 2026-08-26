/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/**
You have a set of integers s, which originally contains all the numbers from 1
to n. Unfortunately, due to some error, one of the numbers in s got duplicated
to another number in the set, which results in repetition of one number and loss
of another number.

You are given an integer array nums representing the data status of this set
after the error.

Find the number that occurs twice and the number that is missing and return them
in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
*/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int duplicated = 0;
    int missing = 0;

    // nums
    // index [0, n -1]
    // value [1, n   ]

    // Apply seen marker loop '-'
    for (int i = 0; i < nums.size(); i++) {
      // std::cout << std::setfill('-') << std::setw(40) << "\n";
      // std::cout << "Index: " << i << "\n";
      // std::cout << "Value: " << nums[i] << "\n";

      // seen number
      int index_seen = abs(nums[i]) - 1;
      if (nums[index_seen] < 0) {
        duplicated = abs(nums[i]);
      } else {
        nums[index_seen] *= -1;
      }

      // for (const int value : nums) {
      //   std::cout << value << ",";
      // }
      // std::cout << "\n";
    }

    // Find missing value : > 0
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        missing = i + 1;
      }
    }

    return {duplicated, missing};
  }
};

void test(vector<int> nums, vector<int> expected) {
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  std::cout << "Nums: \n";
  for (const int value : nums) {
    std::cout << value << ",";
  }
  std::cout << "\n";
  std::cout << "results: \n";
  vector<int> res = Solution().findErrorNums(nums);
  for (const int value : res) {
    std::cout << value << ",";
  }
  std::cout << "\n";
  std::cout << "expected: \n";
  for (const int value : expected) {
    std::cout << value << ",";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  test({1, 2, 2, 4}, {2, 3});
  test({1, 1}, {1, 2});
  test({2, 2}, {2, 1});
  test({1, 2, 3, 1}, {1, 4});
  test({3, 2, 2}, {2, 1});
  test({3, 3, 1}, {3, 2});
  test({1, 5, 3, 2, 2, 7, 6, 4, 8, 9}, {2, 10});

  return 0;
}
