/**
 * ls -1 129-sum_root_to_leaf_numb.cpp | entr -c sh -c "g++
129-sum_root_to_leaf_numb.cpp && ./a.out
 *
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so
that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
 */
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    std::vector<int> storage = {};
    // Recover all tree number
    // Recursive l and r till nullptr reached then add path/number to storage

    goToLeaf(root, &storage, 0);

    int result = 0;
    // std::cout << "Sum of values: " << std::endl;
    for (int x : storage) {
      //   std::cout << x << " ";
      result += x;
    }
    // std::cout << std::endl;
    //
    // Go to leaf and store value (path)
    // Sum array of values recovered

    return result;
  }
  void goToLeaf(TreeNode *node, std::vector<int> *storage, int leafvalue) {
    if (node->val >= 0) {
      leafvalue = leafvalue * 10 + node->val;
    }
    if (node->right == nullptr && node->left == nullptr) {
      storage->push_back(leafvalue);
      return;
    }
    if (node->left) {
      goToLeaf(node->left, storage, leafvalue);
    }
    if (node->right) {
      goToLeaf(node->right, storage, leafvalue);
    }
  }
};

int main(int argc, char *argv[]) {
  std::string line(50, '=');
  Solution test = Solution();
  /**
   *
        4
       / \
      9   0
     / \
    5   1
  */

  TreeNode tree = TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)),
                           new TreeNode(0));

  std::cout << line << std::endl;
  std::cout << test.sumNumbers(&tree) << std::endl;
  std::cout << line << std::endl;

  TreeNode tree123 = TreeNode(1, new TreeNode(2), new TreeNode(3));

  std::cout << test.sumNumbers(&tree123) << std::endl;
  std::cout << line << std::endl;

  return 0;
}
