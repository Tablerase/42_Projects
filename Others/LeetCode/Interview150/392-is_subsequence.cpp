#include <ios>
#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {
      char *p_s = &s[0];
      // char *p_t = &t[0];

      for (int i = 0; i < t.length(); i++){
        std::cout << "Current s: " << *p_s << " Current t: " << t[i] << std::endl;
        if (t[i] == *p_s){
          p_s++;
        }
      }
      if (*p_s == '\0'){
        return true;
      }
      return  false;
    }
};

int main (int argc, char *argv[]) {
  Solution test = Solution();  

  std::cout << std::boolalpha;
  std::cout << test.isSubsequence("abc", "ahbgdc") << std::endl;
  std::cout << test.isSubsequence("axc", "ahbgdc");
  
  return 0;
}
