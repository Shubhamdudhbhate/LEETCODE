#include <iostream>
#include <vector>
using namespace std;

int power(int num, int pw)
{
    if (pw == 0)
        return 1;

    return num * power(num, pw - 1);
}

int powers(int num, int pw)
{
    if (pw == 0)
        return 1;

    int half = powers(num, pw / 2);

    if (pw % 2 == 0)
        return half * half;
    else
        return num * half * half;
}

int fac(int n)
{
    if (n <= 1)
        return 1;

    return n * fac(n - 1);
}

int fibonaci(int n)
{

    if (n < 2)
        return n;

    return fibonaci(n - 1) + fibonaci(n - 2);
}

int sum(int n)
{

    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

bool sorted(vector<int> &arr, int i)
{
    int n = arr.size();

    if (i == n - 1)
        return true;

    if (arr[i] > arr[i + 1])
        return false;

    return sorted(arr, i + 1);
}




int binarySearch(vector<int>& arr, int start, int end, int target) {
    if (start > end) 
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, start, mid - 1, target); // search left
    else
        return binarySearch(arr, mid + 1, end, target); // search right
}



int main()
{
    cout << power(2, 5) << endl; // Output: 32
    cout << powers(2, 30) << endl;
    int k;
    cin >> k;
    cout << "sum :" << sum(k) << endl;

    cout << k << "!  = " << fac(k) << endl;

    vector<int> N;
    for (int i = 0; i < k; i++)
    {
        cout << fibonaci(i) << "  ";
        N.push_back(fibonaci(i));
    }

    cout<<endl;

    cout<<"is it sorted :"<<sorted(N,0)<<endl;

    int search;
    cout<<"enter the value to search   :";   
    cin>>search;
    cout<<"BINARY SEARCH (7)==>("<<fibonaci(7)<<")  the index is :"<<binarySearch(N,0,k,search);

    return 0;
}
