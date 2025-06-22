#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool twoSumBruteForce(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "Found at indices: " << i << " and " << j << endl;
                return true;
            }
        }
    }
    cout << "No pair found.\n";
    return false;
}

bool twoSumBetterForce(vector<int> &arr, int target)
{

    int s = 0;
    int l = arr.size();

    sort(arr.begin(), arr.end());

    while (s < l)
    {

        if (arr[s] + arr[l] == target)
        {
            cout << "Found at indices: " << s << " and " << l << endl;
            return true;
            break;
        }
        else if (arr[s] + arr[l] > target)
        {

            l--;
        }
        else
        {
            s++;
        }
    }

    return false;
}


bool twoSumOptimal(vector<int>& arr, int target) {
    
    unordered_map<int, int> map; // value → index
    cout << " Optimal Approach (Hash Map):\n";

    for (int i = 0; i < arr.size(); i++) {
        int toFind = target - arr[i];
        if (map.find(toFind) != map.end()) {
            cout << "Found at indices: " << map[toFind] << " and " << i << "\n";
            return true;
        }
        map[arr[i]] = i;
    }
    cout << "No pair found.\n";
    return false;
}



int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    int tar = 13;
    int t  =  22;

    cout << "\n-- Brute Force --\n";
    twoSumBruteForce(arr, target);

    cout << twoSumBetterForce(arr, tar) << endl;

    twoSumOptimal(arr, t);

    return 0;
}
