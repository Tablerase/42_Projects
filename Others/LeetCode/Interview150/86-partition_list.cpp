/**
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 *
 *
 * Given the head of a linked list and a value x, partition it such that all
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
 */

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *lessNodesHead = new ListNode();
    ListNode *greaterNodesHead = new ListNode();
    ListNode *less = lessNodesHead;
    ListNode *great = greaterNodesHead;
    for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
      if (curr->val < x) {
        less->next = curr;
        less = less->next;
      } else {
        great->next = curr;
        great = great->next;
      }
    }
    great->next = nullptr;
    less->next = greaterNodesHead->next;

    return lessNodesHead->next;
  }

  void displayList(ListNode *head) {
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
      std::cout << tmp->val << " -> ";
    }
    std::cout << "\n";
  }
};

int main(void) {
  std::string line(50, '=');
  std::cout << line << std::endl;

  Solution test = Solution();
  // std::vector<int> values1 = {1, 4, 3, 2, 5, 2};
  // ListNode *head1 = nullptr;
  // ListNode *tmp = nullptr;
  // for (int v : values1) {
  //   ListNode *newNode = new ListNode(v, nullptr);
  //   if (head1 == nullptr) {
  //     head1 = newNode;
  //     tmp = head1;
  //   } else {
  //     tmp->next = newNode;
  //     tmp = tmp->next;
  //   }
  // }
  //
  // ListNode *res1 = test.partition(head1, 3);
  // std::cout << "Result: ";
  // test.displayList(res1);
  // std::cout << line << "\n";
  //
  // std::vector<int> values2 = {2, 1};
  // ListNode *head2 = nullptr;
  // ListNode *tmp2 = nullptr;
  // for (int v : values2) {
  //   ListNode *newNode = new ListNode(v, nullptr);
  //   if (head2 == nullptr) {
  //     head2 = newNode;
  //     tmp2 = head2;
  //   } else {
  //     tmp2->next = newNode;
  //     tmp2 = tmp2->next;
  //   }
  // }
  // ListNode *res2 = test.partition(head2, 2);
  //
  // std::cout << "\nResult: ";
  // test.displayList(res2);
  // std::cout << line << "\n";
  //

  std::vector<int> val = {1, 4, 3, 0, 2, 5, 2};
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

  ListNode *res1 = test.partition(head, 3);
  std::cout << "Result: ";
  test.displayList(res1);
  std::cout << "Expected: " << "{1, 0, 2, 2, 4, 3, 5 }" << "\n";
  std::cout << line << "\n";
}
