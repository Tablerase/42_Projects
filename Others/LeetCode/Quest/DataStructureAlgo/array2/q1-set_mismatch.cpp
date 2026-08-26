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

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> model_arr(nums.size() + 1, 0);
    model_arr[0] = 1;

    int duplicated = 0;
    int missing = 0;
    for (int i = 0; i < nums.size(); i++) {
      // When value found put model_arr to 1
      int model_nums_count = model_arr[nums[i]];
      if (model_nums_count == 0) {
        model_arr[nums[i]] = 1;

        // For duplicated values
      } else if (model_nums_count == 1) {
        duplicated = nums[i];
      }
    }
    // Search for one value missing 0 in model_arr
    auto it = find(model_arr.begin(), model_arr.end(), 0);
    if (it != model_arr.end()) {
      missing = it - model_arr.begin();
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
