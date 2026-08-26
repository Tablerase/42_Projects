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
#include <list>
#include <map>
#include <sys/types.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    map<int, u_int8_t> indexCount = {};
    int duplicated = 0;
    list<int> missing = {};

    // Loop over
    for (int i = 0; i < nums.size(); i++) {
      // count for duplicated
      const auto it = indexCount.find(nums[i]);
      if (it == indexCount.end()) {
        missing.remove(nums[i]);
        indexCount[nums[i]] = 1;
      } else {
        duplicated = nums[i];
      }

      if (indexCount.find(i + 1) == indexCount.end()) {
        missing.push_back(i + 1);
      }

      std::cout << "in loop missings: ";
      for (const int value : missing) {
        std::cout << value << ",";
      }
      std::cout << "\n";
    }

    return {duplicated, *missing.begin()};
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
