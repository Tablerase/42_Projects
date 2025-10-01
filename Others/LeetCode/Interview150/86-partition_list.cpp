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
  void front_node_insert(ListNode *head, ListNode *node) {
    // TODO: Make a proper front insert
    std::cout << "\nValue to front insert: " << node->val << "\n";
    displayList(head);
    ListNode *prev = head;
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
      if (node->val <= tmp->val) {
        if (tmp == head) {
          head = node;
          node->next = tmp;
        } else {
          prev->next = node;
          node->next = tmp;
        }
        break;
      }
    }
    displayList(head);
  }

  ListNode *partition(ListNode *head, int x) {
    std::cout << "Value pivot: " << x << "\n";
    ListNode *pivot;
    // Find pivot
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
      std::cout << tmp->val << " -> ";
      if (tmp->val == x) {
        pivot = tmp;
        break;
      }
    }
    // Interate after pivot to find nodes value < node pivot and move them to
    // head till nodes values < next node value
    for (ListNode *tmp = pivot; tmp != nullptr && tmp->next != nullptr;
         tmp = tmp->next) {
      if (tmp->next->val < pivot->val) {
        ListNode *save_next = tmp->next;
        tmp->next = save_next->next;
        front_node_insert(head, save_next);
      }
    }
    return head;
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
  std::vector<int> values1 = {1, 4, 3, 2, 5, 2};
  ListNode *head1 = nullptr;
  ListNode *tmp = nullptr;
  for (int v : values1) {
    ListNode *newNode = new ListNode(v, nullptr);
    if (head1 == nullptr) {
      head1 = newNode;
      tmp = head1;
    } else {
      tmp->next = newNode;
      tmp = tmp->next;
    }
  }

  test.partition(head1, 3);
}
