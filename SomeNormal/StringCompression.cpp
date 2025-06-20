#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            // Count consecutive repeating characters
            while (i < chars.size() && chars[i] == currentChar) {
                count++;
                i++;
            }

            // Place the character
            chars[index++] = currentChar;

            // Place the count if > 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};
