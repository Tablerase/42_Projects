/**
 * watchexec --exts cpp "g++ -g file.cpp && ./a.out"
 */

/*
Design an algorithm that accepts a stream of characters and checks if a suffix
of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters
(one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the
suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

StreamChecker(String[] words) Initializes the object with the strings array
words. boolean query(char letter) Accepts a new character from the stream and
returns true if any non-empty suffix from the stream forms a word that is in
words.
*/

#include <iostream>
#include <string>
#include <vector>

class StreamChecker {
private:
  std::string stream_;
  std::vector<std::string> *words_;

public:
  StreamChecker(std::vector<std::string> &words) {
    stream_ = "";
    words_ = &words;
  }

  bool query(char letter) {
    stream_ += letter;

    // Check each words in from the end of the stream
    for (const auto &word : *words_) {
      // std::cout << "Checking: " << word << std::endl;
      // Check suffix possibility and avoid invalid read
      if (stream_.length() < word.length() || stream_.empty() || word.empty()) {
        continue;
      }
      // Check each char in comparison backward - suffix
      for (int i = 1; i <= word.length(); i++) {
        // std::cout << "letter: " << stream_[stream_.length() - i] << " vs "
        //           << word[word.length() - i] << std::endl;
        if (stream_[stream_.length() - i] != word[word.length() - i]) {
          break;
        }
        if (i == word.length()) {
          return true;
        }
      }
    }

    return false;
  }

  friend std::ostream &operator<<(std::ostream &os, const StreamChecker &s) {
    os << "StreamChecker: " << s.stream_;
    os << "\n";
    os << "Possible words: ";
    os << "[";
    for (const auto &word : *s.words_) {
      os << word << ", ";
    }
    os << "]";
    return os;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

void test1() {
  std::vector<std::string> words = {"abc", "xyz"};
  StreamChecker *obj = new StreamChecker(words);
  std::cout << *obj << std::endl;
  std::cout << obj->query('a') << std::endl;
  std::cout << *obj << std::endl;
  std::cout << obj->query('x') << std::endl;
  std::cout << *obj << std::endl;
  std::cout << obj->query('y') << std::endl;
  std::cout << *obj << std::endl;
  std::cout << obj->query('z') << std::endl;
  std::cout << *obj << std::endl;
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
