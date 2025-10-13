/**
 * ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out
 *
 *Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> s_patterns;
    unordered_map<string, char> p_words;

    size_t s_start = 0, s_end = 0;
    int i = 0;
    // Iterate on pattern
    for (char key : pattern) {
      if (s_start > s.size()) {
        return false;
      }
      s_end = s.find(' ', s_start);
      if (s_end == string::npos) {
        s_end = s.size();
      }
      string word_to_check = s.substr(s_start, s_end - s_start);

      cout << "word: |" << word_to_check << "| " << " key: " << key << "\n";

      if (word_to_check.empty()) {
        return false;
      }

      if (s_patterns.count(key) && s_patterns[key] != word_to_check) {
        return false;
      }
      if (p_words.count(word_to_check) && p_words[word_to_check] != key) {
        return false;
      }

      // Assign key/word
      s_patterns[key] = word_to_check;
      p_words[word_to_check] = key;

      s_start = s_end + 1;
      i++;
    }

    // cout << "\n";
    // for (auto &[p, value] : s_patterns) {
    //   cout << "s_pattern: " << p << " value:" << value << '\n';
    // }
    if (s_start < s.size())
      return false;
    if (i != pattern.size())
      return false;
    return true;
  }
};

void test(string pattern, string s, bool expected) {
  Solution tester = Solution();
  string line(50, '=');
  cout << "Pattern: " << pattern << " \n"
       << "S: " << s << " \n"
       << boolalpha << "Solution: " << "\n"
       << tester.wordPattern(pattern, s) << "\n"
       << "Expected: " << expected << " \n"
       << line << "\n";
}

int main(void) {
  test("abba", "dog cat cat dog", true);
  test("abba", "dog cat cat fish", false);
  test("aaaa", "dog cat cat dog", false);
  test("abba", "dog dog dog dog", false);
  test("jquery", "jquery", false);
  return 0;
}
