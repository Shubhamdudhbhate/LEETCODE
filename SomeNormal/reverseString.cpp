#include <string>
#include <vector>
#include <algorithm> // for reverse function
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        // Collect words from the string
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) {
            words.push_back(word); // last word
        }

        // Reverse the word list
        reverse(words.begin(), words.end());

        // Join the reversed words with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += ' ';
            }
        }

        return result;
    }
};
