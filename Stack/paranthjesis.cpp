#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (sol.isValid(input))
        cout << "Valid parentheses!" << endl;
    else
        cout << "Invalid parentheses!" << endl;

    return 0;
}
