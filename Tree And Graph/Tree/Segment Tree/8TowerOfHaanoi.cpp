#include <iostream>
using namespace std;

long long moveCount = 0; // Global counter for total moves

void TowerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        moveCount++; // Count this move
        return;
    }
    TowerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    moveCount++; // Count this move
    TowerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    TowerOfHanoi(n, 'A', 'B', 'C');

    cout << "\nTotal moves: " << moveCount << endl;
    cout << "Formula check: " << ( (1LL << n) - 1 ) << endl; // 2^n - 1
    return 0;
}
