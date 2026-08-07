/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/*
 *Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

int get(int key) Return the value of the key if the key exists, otherwise return
-1.

void put(int key, int value) Update the value of the key if the key exists.

Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key. The
functions get and put must each run in O(1) average time complexity.


Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

#include <iomanip>
#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
  std::list<std::pair<int, int>> lru_list_; // key-value pairs ordered by usage
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator>
      lru_index_; // key -> iterator in queue
  int capacity_;

public:
  LRUCache(int capacity) { capacity_ = capacity; }

  int get(int key) {
    const auto it_list_node = lru_index_.find(key);
    if (it_list_node != lru_index_.end()) {
      // access map pointer to lru list item then value
      const int value = it_list_node->second->second;
      // update position to begin
      lru_list_.splice(lru_list_.begin(), lru_list_, it_list_node->second);
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    // Check if value already exists
    const auto iterator_to_list_node = lru_index_.find(key);
    if (iterator_to_list_node != lru_index_.end()) {
      iterator_to_list_node->second->second = value;
      lru_list_.splice(lru_list_.begin(), lru_list_,
                       iterator_to_list_node->second);
    } else {
      // check capacity
      if (lru_list_.size() >= capacity_) {
        const auto it_last = lru_list_.back();
        lru_index_.erase(it_last.first);
        lru_list_.pop_back();
      }
      // add key-value to lru_list_
      lru_list_.push_front({key, value});
      // add link to new list node to lru_index_ (key -> node)
      lru_index_[key] = lru_list_.begin();
    }
  }

  friend std::ostream &operator<<(std::ostream &os, LRUCache &cache) {
    os << std::setfill('-') << std::setw(50) << '\n';
    os << "List:\n";
    for (const auto item : cache.lru_list_) {
      os << item.first << ',' << item.second << '|' << '\n';
    }
    return os;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void test1() {
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  std::cout << "TEST1" << '\n';
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  LRUCache lRUCache = LRUCache(2);
  std::cout << lRUCache;
  lRUCache.put(1, 1);
  std::cout << lRUCache;
  lRUCache.put(2, 2);
  std::cout << lRUCache;
  std::cout << "Value:" << lRUCache.get(1) << '\n';
  std::cout << lRUCache;
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  std::cout << lRUCache;
  std::cout << "Value:" << lRUCache.get(2) << '\n'; // returns -1 (not found)
  std::cout << lRUCache;
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  std::cout << lRUCache;
  std::cout << "Value:" << lRUCache.get(1) << '\n'; // return -1 (not found)
  std::cout << lRUCache;
  lRUCache.get(3); // return 3
  std::cout << lRUCache;
  lRUCache.get(4); // return 4
  std::cout << lRUCache;
}

void test2() {
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  std::cout << "TEST2" << '\n';
  std::cout << std::setfill('=') << std::setw(50) << '\n';
  LRUCache lRUCache = LRUCache(2);
  std::cout << lRUCache;
  lRUCache.put(2, 1);
  std::cout << lRUCache;
  lRUCache.put(2, 2);
  std::cout << lRUCache;
  std::cout << "Value:" << lRUCache.get(2) << '\n'; // expected 2;
  std::cout << lRUCache;
  lRUCache.put(1, 1);
  std::cout << lRUCache;
  lRUCache.put(4, 1);
  std::cout << lRUCache;
  std::cout << "Value:" << lRUCache.get(2) << '\n'; // return -1 (not found)
  std::cout << lRUCache;
}

int main(int argc, char *argv[]) {
  test1();
  // test2();
  return 0;
}

/*
 *
cpp unordered_map use hash table => O 1
cpp map use red black tree => O log N

Hash Table

Bucket Index    Content (Hash Chains)
-------------------------------------------------------
[ Bucket 0 ] -> [ "Alice" : 95 ] -> nullptr
[ Bucket 1 ] -> EMPTY
[ Bucket 2 ] -> [ "Dave" : 81 ] -> [ "Charlie" : 72 ] -> nullptr  (Hash
Collision) [ Bucket 3 ] -> [ "Bob" : 88 ] -> nullptr

Unbalanced (Standard BST):         Balanced (Red-Black / AVL):
    10                                    20
      \                                  /  \
       20                              10    30
         \                                    \
          30                                   40
            \
             40
Lookup: O(N)                           Lookup: O(log N)
*/
