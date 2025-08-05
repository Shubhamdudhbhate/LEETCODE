#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {



    cout << "----- 1. BASIC STRING -----\n";
    // C-style string
    char cname[] = "Shubham"; // ends with '\0'
    cout << "C-style string: " << cname << endl;

    // C++ string
    string s1 = "Hello", s2("World"), s3(5, '*');
    cout << "C++ strings: " << s1 << ", " << s2 << ", " << s3 << endl;





    cout << "\n----- 2. STRING INPUT -----\n";
    string line;
    cout << "Enter a sentence: ";
    getline(cin, line);  // Input with spaces
    cout << "You entered: " << line << endl;





    cout << "\n----- 3. COMMON OPERATIONS -----\n";
    string str = "OpenAI";
    cout << "Length: " << str.length() << endl;
    cout << "First char: " << str[0] << endl;
    str[1] = 'X';
    cout << "Modified: " << str << endl;




    cout << "\n----- 4. TRAVERSAL -----\n";
    for (int i = 0; i < str.length(); i++) cout << str[i] << " ";
    cout << "\n";
    
    for (char c : str) cout << c << " ";
    cout << "\n";



    cout << "\n----- 5. STRING FUNCTIONS -----\n";
    string A = "algorithm", B = "algo";
    cout << "Substring: " << A.substr(0, 5) << endl;
    cout << "Find 'go': " << A.find("go") << endl;
    A.replace(0, 5, "crypto");
    cout << "After replace: " << A << endl;
    A.insert(3, "123");
    cout << "After insert: " << A << endl;
    A.erase(3, 3);
    cout << "After erase: " << A << endl;



    

    cout << "\n----- 6. COMPARISON & SORTING -----\n";
    string cmp1 = "abc", cmp2 = "abd";
    cout << (cmp1 < cmp2 ? "abc < abd\n" : "abd < abc\n");
    sort(cmp1.begin(), cmp1.end());
    cout << "Sorted: " << cmp1 << endl;





    cout << "\n----- 7. TYPE CONVERSION -----\n";
    int x = 123;
    string sx = to_string(x);
    cout << "to_string: " << sx << endl;
    cout << "stoi: " << stoi("456") + 10 << endl;






    cout << "\n----- 8. PALINDROME CHECK -----\n";
    string p = "madam";
    bool isPal = true;
    for (int i = 0, j = p.length()-1; i < j; i++, j--) {
        if (p[i] != p[j]) { isPal = false; break; }
    }
    cout << p << " is " << (isPal ? "Palindrome" : "Not Palindrome") << endl;






    cout << "\n----- 9. ADVANCED: KMP Prefix Table -----\n";
    string pattern = "ababaca";
    vector<int> lps(pattern.length(), 0);
    for (int i = 1, len = 0; i < pattern.length();) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    cout << "LPS Table: ";
    for (int v : lps) cout << v << " ";
    cout << endl;








    cout << "\n----- 10. ADVANCED: Z-ALGORITHM -----\n";
    string zstr = "abxabcabcaby";
    int n = zstr.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && zstr[z[i]] == zstr[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    cout << "Z values: ";
    for (int val : z) cout << val << " ";
    cout << endl;








    cout << "\n----- 11. ADVANCED: TRIE STRUCTURE -----\n";
    struct TrieNode {
        TrieNode* child[26] = {nullptr};
        bool end = false;
    };
    auto insert = [](TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->child[i]) node->child[i] = new TrieNode();
            node = node->child[i];
        }
        node->end = true;
    };
    auto search = [](TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->child[i]) return false;
            node = node->child[i];
        }
        return node->end;
    };

    TrieNode* root = new TrieNode();
    insert(root, "hello");
    insert(root, "world");
    cout << "Search 'hello': " << (search(root, "hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'cat': " << (search(root, "cat") ? "Found" : "Not Found") << endl;





    

    return 0;
}
