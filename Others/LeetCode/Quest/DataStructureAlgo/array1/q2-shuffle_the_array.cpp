/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> res = {};

    for (int start = 0, middle = nums.size() / 2; start < nums.size() / 2;
         start++, middle++) {
      res.push_back(nums[start]);
      res.push_back(nums[middle]);
    }

    return res;
  }
};

void test(vector<int> nums, int n) {
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  std::cout << "N: " << n << '\n';
  std::cout << "Nums: \n";
  for (const int value : nums) {
    std::cout << value << ",";
  }
  std::cout << "\n";
  vector<int> res = Solution().shuffle(nums, n);
  for (const int value : res) {
    std::cout << value << ",";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  test({2, 5, 1, 3, 4, 7}, 3);

  return 0;
}
