/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/*
Given a data stream input of non-negative integers a1, a2, ..., an, summarize
the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.

void addNum(int value) Adds the integer value to the stream.

int[][] getIntervals() Returns a summary of the integers in the stream currently
as a list of disjoint intervals [starti, endi]. The answer should be sorted by
starti.

  • Disjoint (No overlap):

    [1,3]  and  [5,8]

  On a number line:

    ---[1====3]------[5========8]---

  There is no point shared between them.

  • Overlapping (Not disjoint):

    [1,5]  and  [3,8]

  On a number line:

    ---[1======(3]===5]========8]---

  The segment [3,5] is shared by both intervals.

  1. addNum(1)
      • Numbers seen: {1}
      • Result: [[1, 1]]
  2. addNum(3)
      • Numbers seen: {1,3}
      • Notice there is a gap (we haven't seen 2).
      • Result: [[1, 1], [3, 3]]  (These are 2 disjoint intervals)
  3. addNum(7)
      • Numbers seen: {1,3,7}
      • Result: [[1, 1], [3, 3], [7, 7]]
  4. addNum(2)
      • Numbers seen: {1,2,3,7}
      • Look at what 2 does: it bridges the gap between [1, 1] and [3, 3].
      • Now 1,2,3 form a continuous range:
      • Result: [[1, 3], [7, 7]]
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class SummaryRanges {
private:
  vector<vector<int>> intervals_;

  void mergeIntervals(const int merge_index_s, const int merge_index_e) {
    // Guard clause: ensure indices are within valid bounds
    if (merge_index_s < 0 || merge_index_e >= intervals_.size()) {
      std::cerr << "Out of range merge: \nstart: " << merge_index_s
                << " end: " << merge_index_e << std::endl;
      return;
    }

    vector<int> &interval_s = intervals_[merge_index_s];
    vector<int> &interval_e = intervals_[merge_index_e];
    int &end_to_check = interval_s[1];
    int &start_to_merge = interval_e[0];

    // Merge with next interval if possible
    if (end_to_check == start_to_merge - 1) {
      interval_e[0] = interval_s[0];
      intervals_.erase(intervals_.begin() + merge_index_s);
    }
  }

public:
  SummaryRanges() {}

  void addNum(int value) {
    // Verify neg values
    if (value < 0) {
      return;
    }
    // Try to add value to existing intervals
    int insertion_index = 0;
    for (int interval_index = 0; interval_index < intervals_.size();
         interval_index++) {
      vector<int> &interval_to_check = intervals_[interval_index];
      int &start_i = interval_to_check[0];
      int &end_i = interval_to_check[1];

      // Check start and end of interval available position
      if (value == start_i - 1) {
        start_i = value;
        if (interval_index >= 1) {
          mergeIntervals(interval_index - 1, interval_index);
        }
        return;
      } else if (value == end_i + 1) {
        end_i = value;
        if (interval_index < intervals_.size() - 1) {
          mergeIntervals(interval_index, interval_index + 1);
        }
        return;
      } else if (value >= start_i && value <= end_i) {
        return;
      }

      if (value > end_i) {
        insertion_index++;
      }
    }

    // Create new interval and insert in sorted position
    intervals_.insert(intervals_.begin() + insertion_index, {value, value});
  }

  vector<vector<int>> getIntervals() { return intervals_; }

  friend std::ostream &operator<<(std::ostream &os, const SummaryRanges &s) {
    os << "SummaryRanges: ";
    os << "[";
    for (const auto &interval : s.intervals_) {
      os << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    os << "]";
    return os;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void test1() {
  SummaryRanges *obj = new SummaryRanges();
  obj->addNum(1);
  cout << *obj << endl;
  obj->addNum(3);
  cout << *obj << endl;
  obj->addNum(7);
  cout << *obj << endl;
  obj->addNum(2);
  cout << *obj << endl;
  obj->addNum(6);
  cout << *obj << endl;
  delete obj;
}

void test2() {
  cout << setfill('+') << setw(50) << '\n';
  SummaryRanges *obj = new SummaryRanges();
  obj->addNum(1);
  cout << *obj << endl;
  obj->addNum(0);
  cout << *obj << endl;
  delete obj;
}

void test3() {
  cout << setfill('+') << setw(50) << '\n';
  SummaryRanges *obj = new SummaryRanges();
  obj->addNum(6);
  cout << *obj << endl;
  obj->addNum(6);
  cout << *obj << endl;
  obj->addNum(0);
  cout << *obj << endl;
  obj->addNum(4);
  cout << *obj << endl;
  obj->addNum(8);
  cout << *obj << endl;
  obj->addNum(7);
  cout << *obj << endl;
  obj->addNum(7);
  cout << *obj << endl;
  delete obj;
}

int main(int argc, char *argv[]) {
  test1();
  test2();
  test3();
  return 0;
}
