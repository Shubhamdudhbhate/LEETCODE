#include <iostream>
#include <string> // optional but recommended for string operations
#include <algorithm> // for reverse function
using namespace std;

int main()
{

    char chr[] = "Sujit Dudhbhate"; // Static character array initialization
    cout << chr << endl;

    // chr = "How  are You " + chr + " All Good! ";   // This line will cause an error because chr is a char array and cannot be reassigned like a string

    string str1 = "Shubham Goroba 4 "; // dynamic string initialization
    cout << str1 << "length of string is : " << str1.length() << endl;

    string str = "Shubham Goroba 3 ";

    cout << (str == str1) << endl; //  1   This will not work as expected, it compares the address of str and str1, not their content
    cout << (str > str1) << endl;  //  0

    string str2 = "Dudhbhate";
    cout << str2 << endl;

    string str3 = str1 + str2; // Concatenating strings

    string str4 = "How  are You " + str3 + " All Good! "; // Concatenating strings
    cout << str4 << endl;

    string str5;
    // cin >> str5;        // Using cin to read a string (stops at whitespace)  so getline is better
    // cin.ignore();       // Clear the newline character from the input buffer
    getline(cin, str5); // Using getline to read a full line including spaces
    cout << "You entered: " << str5 << endl;



  reverse(str5.begin(), str5.end());
  cout << "Reversed string: " << str5 << endl;


    for (char ch : str5)
    {
        if (ch == ' ')
        {
            cout << "_"; // Output underscores for spaces
        }
        else
        {
            cout << ch; // Output other characters as they are
        }
    }

    for (int i = 0; i < str3.length(); i++)
    {
        if (str5[i] == ' ')
        {
            cout << "_"; // Output underscores for spaces
        }
        else
        {
            cout << str3[i]; // Output other characters as they are
        }
    }

    return 0;
}