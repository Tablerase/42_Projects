/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/*
You are part of a university admissions office and need to keep track of the kth
highest test score from applicants in real-time. This helps to determine cut-off
marks for interviews and admissions dynamically as new applicants submit their
scores.

You are tasked to implement a class which, for a given integer k, maintains a
stream of test scores and continuously returns the kth highest test score after
a new score has been submitted. More specifically, we are looking for the kth
highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the
stream of test scores nums. int add(int val) Adds a new test score val to the
stream and returns the element representing the kth largest element in the pool
of test scores so far.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class KthLargest {
private:
  int cut_off_;
  std::vector<int> *nums_;

public:
  KthLargest(int k, std::vector<int> &nums) {
    cut_off_ = k;
    nums_ = &nums;
    std::sort(nums_->begin(), nums_->end(),
              [](const int &a, const int &b) { return a > b; });
  }

  int add(int val) {
    std::vector<int>::iterator it =
        std::lower_bound(nums_->begin(), nums_->end(), val,
                         [](const int &a, const int &b) { return a > b; });
    nums_->insert(it, val);
    return nums_->at(cut_off_ - 1);
  }

  friend std::ostream &operator<<(std::ostream &os, KthLargest &c) {
    os << "KthLargest: " << "k:" << c.cut_off_ << " nums:";
    for (const auto element : *c.nums_) {
      os << element << " ";
    }
    os << "\n";
    return os;
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

void test1() {
  std::vector<int> nums = {4, 5, 8, 2};
  KthLargest kthLargest = KthLargest(3, nums);
  std::cout << kthLargest;
  std::cout << "Add: " << kthLargest.add(3) << "\n";
  std::cout << kthLargest;
  std::cout << "Add: " << kthLargest.add(5) << "\n";
  std::cout << kthLargest;
  std::cout << "Add: " << kthLargest.add(10) << "\n";
  std::cout << kthLargest;
  std::cout << "Add: " << kthLargest.add(9) << "\n";
  std::cout << kthLargest;
  std::cout << "Add: " << kthLargest.add(4) << "\n";
  std::cout << kthLargest;
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
