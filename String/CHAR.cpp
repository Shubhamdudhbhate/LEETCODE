#include <iostream>
using namespace std;

int main()
{

    char st[23];
    cout << "enter sentence " << endl;              // Declare a character array to hold the string input
    cin.getline(st, 23);                            // Using getline to read a full line including spaces
    cout << "You entered sentence: " << st << endl; // Output: whatever the user

    for (char ch : st)
    {
        if (ch == ' ')
        {
            cout << "_"; // Output underscores for spaces
            ch == '&';   // This line seems to be a mistake, it does nothing
        }
        else
        {
            cout << ch; // Output other characters as they are
        }
    }

    cout << endl;

    cout << "You entered sentence: " << st << endl;

    char St[50];
    cout << "Enter a single word: ";
    cin >> St; // Using cin to read a string (stops at whitespace)
    cout << "You entered word: " << St << endl;

    char SD; // Declare a character variable to hold a single character input
    cout << "Enter a single  only  single character: ";
    cin >> SD;
    cout << "You entered character: " << SD << endl; // Output: whatever the user

    string str = "! Hello World";
    cout << str << endl;                                    // Output: Hello, World!
    cout << "How  are You " << st << " All Good! " << endl; // Output: 13

    // Accessing characters
    cout << "First character: " << str[0] << endl;               // Output: H
    cout << "Last character: " << str[str.length() - 1] << endl; // Output: !

    // Modifying a character
    str[7] = 'C';
    cout << "Modified string: " << str << endl; // Output: Hello, Corld!

    return 0;
    
}