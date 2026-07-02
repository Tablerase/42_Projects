/**
 * watchexec --exts cpp "g++ file.cpp && ./a.out"
 */

/**
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following
sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  unsigned long long factorial(int n) {
    if (n <= 1)
      return 1;
    unsigned long long res = 1;

    for (int i = n; i > 1; i--) {
      res = res * i;
    }

    return res;
  }

  string getPermutation(int n, int k) {
    unsigned long long totalPermutations = factorial(n);
    string res;
    std::vector<int> permutElem;

    // Create Set of permutation
    for (int i = 1; i <= n; i++) {
      permutElem.push_back(i);
    }

    int permutIndex = 0;
    while (!permutElem.empty()) {
      for (int i = 0; i < permutElem.size(); i++) {
        // current num means (permutElem.size - 1)! remaining possibilities
        const unsigned long long remainingPossibilities =
            factorial(permutElem.size() - 1);
        if (permutIndex + remainingPossibilities >= k) {
          res = res + to_string(permutElem[i]);
          permutElem.erase(permutElem.begin() + i);
          break;
        }
        permutIndex += remainingPossibilities;
      }
    }
    return res;
  }
};

void Test(int n, int k, string expected) {
  Solution s = Solution();
  std::cout << "Test: " << n << " values for k: " << k << '\n'
            << "Result: " << s.getPermutation(n, k) << '\n'
            << "Expected: " << expected << '\n';
}

int main() {
  Solution s = Solution();

  Test(3, 3, "213");
  Test(4, 9, "2314");
  Test(3, 1, "123");
  return 0;
}
