/**
 * watchexec -r -e cpp "g++ -g file.cpp && ./a.out"
 */

/**
Given the array nums, for each nums[i] find out how many numbers in the array
are smaller than it. That is, for each nums[i] you have to count the number of
valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int sumOfInferiorNumbers(int comparator, vector<int> &nums_to_compare) {
    int sum = 0;
    for (const int num : nums_to_compare) {
      if (num < comparator) {
        sum++;
      }
    }
    return sum;
  }

public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> res = {};
    for (const int num : nums) {
      res.push_back(sumOfInferiorNumbers(num, nums));
    }
    return res;
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
  vector<int> res = Solution().smallerNumbersThanCurrent(nums);
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
  test({8, 1, 2, 2, 3}, {4, 0, 1, 1, 3});
  test({6, 5, 4, 8}, {2, 1, 0, 3});
  test({7, 7, 7, 7}, {0, 0, 0, 0});

  return 0;
}
