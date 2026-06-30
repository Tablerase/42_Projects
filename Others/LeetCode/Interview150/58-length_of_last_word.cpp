/**
*
ls -1 file.cpp | entr -c sh -c "g++ file.cpp && ./a.out"

Given a string s consisting of words and spaces, return the length of the last
word in the string.

A word is a maximal substring consisting of non-space characters only.


Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

*/
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int l = 0;
    int end = s.size() - 1;

    // Trim end of string
    while (end >= 0 && s[end] == ' ') {
      end--;
    }

    // Count last word
    while (end >= 0 && s[end] != ' ') {
      end--;
      l++;
    }

    return l;
  }
};

void doTest(string toTest) {
  string line(50, '=');
  cout << line << endl;

  Solution test = Solution();

  cout << "String: " << toTest << endl;
  cout << "Result: ";
  cout << test.lengthOfLastWord(toTest) << endl;
}

int main(int argc, char *argv[]) {
  doTest("Hello World");
  doTest("   fly me   to   the moon  ");
  doTest("luffy is still joyboy");

  return 0;
}
