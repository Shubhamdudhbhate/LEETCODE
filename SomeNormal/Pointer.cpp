#include <iostream>
#include <vector>
using namespace std;

void ChangeA(int &b)
{
    b = 100; // Change the value of a using pointer
}

int main()
{
    int a = 10;

    // Step 1: Declare a pointer to a
    int *ptr = &a; // ptr stores the address of variable a

    // Step 2: Declare a pointer to a pointer (double pointer)
    int **parptr = &ptr; // parptr stores the address of ptr (pointer to pointer)

    // ------------------------------
    // 📌 Print all basic pointer info
    // ------------------------------

    cout << " [          1          ] Value of a: " << a << endl;          // 10
    cout << " [          2           ] Address of a (&a): " << &a << endl; // address of a

    cout << " [          2           ] Value of ptr (i.e., address of a): " << ptr << endl;
    cout << " [          1          ] Value pointed by ptr (*ptr) (Value of a): " << *ptr << endl;

    cout << " [          3           ]  (&ptr): " << &ptr << endl;
    cout << " [          3           ] Value of parptr (i.e., address of ptr): " << parptr << endl;
    cout << " [          2           ] Value pointed by parptr (*parptr = ptr) " << *parptr << endl;
    cout << " [          1           ] Value pointed by pointer to pointer (**parptr = a): " << **parptr << endl;
 





    cout<<ptr << endl; 
    cout<<*ptr << endl; 

    ptr++;
    cout << "value of ptr after incrementing: " << ptr << endl; // Incrementing pointer moves it to the next integer address
    
    *ptr++;
    cout << "value of *ptr after incrementing: " << *ptr<<" "<<ptr<< endl; // Dereferencing ptr after incrementing gives undefined behavior
    
    ptr--;
    cout << "value of ptr after decrementing: " << ptr << endl; // Decrementing pointer moves it back to the previous integer address
  
    *ptr--;
    cout << "value of *ptr after decrementing: " << *ptr <<"  "<<ptr<< endl; // Dereferencing ptr after decrementing gives undefined behavior
  
    ptr++;  



    // ------------------------------
    // ✅ Modify value of a using pointer
    // ------------------------------
    *ptr = 20;
    cout << "\nAfter modifying *ptr = 20" << endl;
    cout << "New value of a: " << a << endl;

    // ------------------------------
    // ✅ Modify value of a using double pointer
    // ------------------------------
    **parptr = 30;
    cout << "\nAfter modifying **parptr = 30" << endl;
    cout << "New value of a: " << a << endl;


    int b = 10;
    ChangeA(b);                                           // Call function to change value of b
    cout << "Value of b after ChangeA(b): " << b << endl; // b is now 100


    parptr = NULL;
    cout << "value  of parptr): " << parptr << endl; // parptr is now a null pointer it returns 0
    cout << "value of *parptr: " << *parptr << endl; // dereferencing a null pointer is undefined behavior


  int c = 10;
  int *ptr1 = &c; // ptr1 stores the address of variable c








    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;

    cout << "\nUsing pointer arithmetic:\n";
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    }
    cout << "\nAddresses:\n";
    for (int i = 0; i < 5; i++) {
        cout << "&arr[" << i << "] = " << &arr[i] << ", (p + " << i << ") = " << (p + i) << endl;
    }

    // Modify array using pointer
    *(p + 2) = 100;  // Change 3rd element to 100

    cout << "\nAfter modifying *(p + 2) = 100:\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }


    return 0;
}
