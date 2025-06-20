#include <string>
#include <cctype> // for isalnum and tolower
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int last = s.length() - 1;

        while (start < last) {


            while (start < last && !isalnum(s[start])) start++;
            while (start < last && !isalnum(s[last])) last--;

 
            if (tolower(s[start]) != tolower(s[last])) {
                return false;
            }

            start++;
            last--;
        }
        return true;
    }
};
