/**
 * repl / auto recompile:
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 * debug:
 * valgrind ./a.out
 * lldb ./a.out
 */

/**
 *You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their nodes
contains a single digit. Add the two numbers and return the sum as a linked
list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 */
#include <iostream>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() { delete next; }
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *resultHead = new ListNode(0);
    ListNode *res = resultHead;
    int modulo = 0;
    // Add values from each List and create a node at each addition
    ListNode *cur_l1 = l1;
    ListNode *cur_l2 = l2;
    while (cur_l1 != nullptr || cur_l2 != nullptr) {
      std::cout << "l1: " << (cur_l1 != nullptr ? cur_l1->val : 0)
                << " l2: " << (cur_l2 != nullptr ? cur_l2->val : 0) << "\n";
      int sum = (cur_l1 != nullptr ? cur_l1->val : 0) +
                (cur_l2 != nullptr ? cur_l2->val : 0) + modulo;
      int val = sum % 10;
      // Keep value in case sum > 10 for next addition
      modulo = sum / 10;
      std::cout << "Sum: " << sum << " Val: " << val << " Modulo: " << modulo
                << std::endl;
      res->next = new ListNode(val);
      res = res->next;
      displayList(resultHead->next);
      if (cur_l1 != nullptr) {
        cur_l1 = cur_l1->next;
      }
      if (cur_l2 != nullptr) {
        cur_l2 = cur_l2->next;
      }
    }
    // Handle modulo remainder
    if (modulo) {
      res->next = new ListNode(modulo);
      res = res->next;
    }
    return resultHead->next;
  }

  void displayList(ListNode *head) {
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
      std::cout << tmp->val;
      if (tmp->next != nullptr) {
        std::cout << " -> ";
      }
    }
    std::cout << "\n";
  }
};

ListNode *createList(std::vector<int> v) {
  std::vector<int> val = v;
  ListNode *head = nullptr;
  ListNode *tmp = nullptr;
  for (int v : val) {
    ListNode *newNode = new ListNode(v, nullptr);
    if (head == nullptr) {
      head = newNode;
      tmp = head;
    } else {
      tmp->next = newNode;
      tmp = tmp->next;
    }
  }
  return head;
}

void doTest(std::vector<int> l1, std::vector<int> l2) {
  ListNode *l1_head = createList(l1);
  ListNode *l2_head = createList(l2);

  std::string line(50, '=');
  std::cout << line << std::endl;

  Solution test = Solution();
  test.displayList(l1_head);
  test.displayList(l2_head);

  ListNode *sum = test.addTwoNumbers(l1_head, l2_head);
  std::cout << "Result: ";
  test.displayList(sum);
}

int main(int argc, char *argv[]) {
  // int modulo = 0;
  // int sum = (9) + (9) + modulo;
  // int val = sum % 10;
  // modulo = sum / 10;
  // std::cout << "Sum: " << sum << " Val: " << val << " Modulo: " << modulo
  //           << std::endl;

  Solution test = Solution();
  doTest({2, 4, 3}, {5, 6, 4});
  std::cout << "Expected: " << 807 << "\n";
  doTest({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9});
  std::cout << "Expected: " << "8,9,9,9,0,0,0,1" << "\n";
  return 0;
}
