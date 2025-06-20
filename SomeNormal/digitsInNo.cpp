#include <iostream>
#include <vector>
#include <algorithm> // for reverse function
#include <string>
#include <cmath> // for log function
#include <limits.h> // for INT_MAX
using namespace std;

bool IsArmstrong(int n) // Function to check if a number is an Armstrong number
{
    int sum = 0;
    int original = n;
    int count = 0;

    // Count the number of digits
    while (n != 0)
    {
        n /= 10;
        count++;
    }

    n = original; // Reset n to original value

    // Calculate the sum of digits raised to the power of count
    while (n != 0)
    {
        int digit = n % 10;
        sum += pow(digit, count);
        n /= 10;
    }

    return sum == original; // Check if the sum equals the original number
}

void printDigitsInNo(int n)
{
    int sum = 0;
    int count = 0;
    int product = 1;

    vector<int> Dg;

    while (n != 0)
    {

        int digit = n % 10;
        Dg.push_back(digit); // Store the digit in the vector

        product *= digit; // Calculate the product of digits
        sum += digit;

        count++;

        n = n / 10;
    }

    reverse(Dg.begin(), Dg.end());

    cout << "Digits in the number are:" << endl;

    for (int i = 0; i < Dg.size(); i++)
    {
        cout << Dg[i] << " ";
    }

    cout << endl
         << "Total digits are: " << count << endl;
    cout << "Sum of digits is: " << sum << endl;
    cout << "Product of digits is: " << product << endl;
}








//  Euclid's Algorithm

int GCDS(int a, int b){

if(a==0 && b==0){
    return 0; 
}
if(a>b){
    return GCDS(a-b,b); 
} else if(a<b){
    return GCDS(a,b-a);
} else {
    return a;
}

return 1; 

}











int GCD(int a, int b)
{

    int gcd = 1;

    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}




int LCM(int a, int b)
{

    cout<<" LCM is: " <<  (a * b) / GCDS(a, b) << endl;
    return (a * b) / GCD(a, b);
     // Calculate LCM using GCD  eqn--->> number = LCM * GCD
}




int reverse(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int digit = n % 10;

        if( rev > (INT_MAX - digit) / 10) {
            cout << "Overflow occurred while reversing the number." << endl;
            return 0; 
        }
        // Check for overflow before multiplying and adding
         if (rev < (INT_MIN + digit) / 10) {
            cout << "Underflow occurred while reversing the number." << endl;
            return 0; 
        }


        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}   



bool Palindrome(int n)
{
    int original = n;
    int reversed = 0;

    while (n != 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed; // Check if the original number is equal to the reversed number
}





int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printDigitsInNo(n);
    cout << endl;



    cout << "  Now,Again enter digit  for finding by log(n) method " << endl;
    int num;
    cin >> num;
    cout << "Digits in the number are: " << int(log10(num) + 1) << endl;
    cout << " to check the no. an Armstrong or not  " << endl;




    int nump;
    cin >> nump;
    cout << "Is the number " << nump << " an Armstrong number? " << (IsArmstrong(nump) ? "Yes" : "No") << endl;





    cout << "Enter two numbers to find GCD and LCM: ";
    int a, b;
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << GCD(a, b)<<"  "<< GCDS(a, b)<<endl;
    cout << "LCM of " << a << " and " << b << " is: " << LCM(a, b) << endl;
   



   int rev;
    cout << "Enter a number to reverse: ";      
    cin >> rev;
    int reversedNumber = reverse(rev);
    if (reversedNumber != 0) {
        cout << "Reversed number is: " << reversedNumber << endl;
    }
   

 int palin;
    cout << "Enter a number to check if it's a palindrome: ";
    cin >> palin;
    cout << "Is the number " << palin << " a palindrome? " << (Palindrome(palin) ? "Yes" : "No") << endl;



    

    return 0;
}