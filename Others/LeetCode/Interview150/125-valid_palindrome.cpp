#include <cctype>
#include <ios>
#include <iostream>
#include <string>
using std::string;

class Solution {
  public:
      bool isPalindrome(string s) {
        string clean;
        for (char c : s){
          if (isalnum(c)){
            clean += tolower(c);
          }
        }
        // std::cout << "Origin: " << s << " Clean: " << clean << std::endl;

        auto pBegin = &clean[0];
        auto pEnd = &clean[clean.length()] - 1;
        for ( char c : clean) {
          // std::cout << "Start: " << *pBegin << " End: " << *pEnd << std::endl;
          if (pBegin == pEnd){
            return true;
          }
          if (*pBegin++ != *pEnd--){
            return false;
          }
        }
        return true; 
      }
};

int main(void){
  Solution test = Solution();
  std::cout << std::boolalpha << test.isPalindrome("IHIHI") << std::endl;
  std::cout << std::boolalpha << test.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
}
