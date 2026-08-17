/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data
structure. int get(int key) Gets the value of the key if the key exists in the
cache. Otherwise, returns -1. void put(int key, int value) Update the value of
the key if present, or inserts the key if not already present. When the cache
reaches its capacity, it should invalidate and remove the least frequently used
key before inserting a new item. For this problem, when there is a tie (i.e.,
two or more keys with the same frequency), the least recently used key would be
invalidated. To determine the least frequently used key, a use counter is
maintained for each key in the cache. The key with the smallest use counter is
the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to
the put operation). The use counter for a key in the cache is incremented either
a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

#include <iomanip>
#include <iostream>
#include <list>
#include <unordered_map>

class LFUCache {
private:
  struct LFUItem {
    int key;
    int value;
    int count;
    std::list<int>::iterator it_freq;
  };

  int capacity_;
  int min_freq_;
  std::unordered_map<int, std::list<int>>
      freq_map_; // most recent of each bucket in back;
  std::unordered_map<int, LFUItem> lfu_map_;

  void touch(LFUItem &element) {
    freq_map_[element.count].erase(element.it_freq);
    element.count++;
    freq_map_[element.count].push_back(element.key);
    element.it_freq = prev(freq_map_[element.count].end());
    if (freq_map_[min_freq_].empty()) {
      min_freq_++;
    }
  }

public:
  LFUCache(int capacity) {
    if (capacity == 0) {
      throw std::invalid_argument("Capacity 0 not allowed!");
    }
    capacity_ = capacity;
    min_freq_ = 1;
  }

  int get(int key) {
    const auto res = lfu_map_.find(key);
    if (res != lfu_map_.end()) {
      touch(res->second);
      return res->second.value;
    }
    return -1;
  }

  void put(int key, int value) {
    const auto res = lfu_map_.find(key);
    if (res == lfu_map_.end()) {
      // check capacity
      if (lfu_map_.size() >= capacity_) {
        auto &least_freq = freq_map_[min_freq_];
        // std::cout << "Evicting least freq: " << min_freq_
        //           << " value: " << lfu_map_[least_freq.front()].value <<
        //           "\n";
        lfu_map_.erase(least_freq.front());
        least_freq.pop_front();
        // std::cout << "After eviction: " << *this;
      }
      min_freq_ = 1;
      freq_map_[min_freq_].push_back(key);
      lfu_map_[key] = {key, value, 1, next(freq_map_[1].end(), -1)};
    } else {
      res->second.value = value;
      touch(res->second);
    }
  }

  friend std::ostream &operator<<(std::ostream &os, LFUCache &c) {
    os << std::setfill('-') << std::setw(50) << "\n";
    os << "Cache: " << "cap:" << c.capacity_ << " min_freq_:" << c.min_freq_
       << "\n";
    for (const auto element : c.freq_map_) {
      os << "\n----- Freq: " << element.first << " \n ";
      for (const auto list_item : element.second) {
        const auto item = c.lfu_map_[list_item];
        os << "k: " << item.key << " v: " << item.value << " c: " << item.count;
        os << " | ";
      };
    };
    os << "\n";
    return os;
  }
};

void test1() {
  LFUCache lfu = LFUCache(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  std::cout << lfu;
  std::cout << "Get: " << lfu.get(1) << "\n";
  std::cout << lfu;
  lfu.put(3, 3);
  std::cout << lfu;
  std::cout << "Get: " << lfu.get(2) << "\n";
  std::cout << "Get: " << lfu.get(3) << "\n";
  std::cout << lfu;
  lfu.put(4, 4);
  std::cout << lfu;
  std::cout << "Get: " << lfu.get(1) << "\n";
  std::cout << "Get: " << lfu.get(3) << "\n";
  std::cout << "Get: " << lfu.get(4) << "\n";

  std::cout << std::setfill('=') << std::setw(50) << "\n";
}

void test2() {
  LFUCache lfu = LFUCache(2);
  lfu.put(3, 1);
  std::cout << lfu;
  lfu.put(2, 1);
  std::cout << lfu;
  lfu.put(2, 2);
  std::cout << lfu;
  lfu.put(4, 4);
  std::cout << "Get: " << lfu.get(2) << "\n";
  std::cout << lfu;
}

int main(int argc, char *argv[]) {
  test1();
  test2();
  return 0;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
