#include <iostream>
#include <vector>
using namespace std;



 bool isValid(vector<int> &nums, int mid, int students) {
    int studentCount = 1; // Start with one student 
    int pageSum = 0; // Initialize the sum of pages for the current student

    for (int i = 0; i < nums.size(); i++) {
        pageSum += nums[i]; // Add pages of the current book

        // If the sum exceeds mid, allocate to the next student
        if (pageSum > mid) {
            studentCount++; // Increment student count
            pageSum = nums[i]; // Start new sum with current book

            // If students exceed limit, return false
            if (studentCount > students) {
                return false;
            }
        }
    }

    return true; // If we can allocate within the limit, return true
}



int findPages(vector<int> &nums, int students) {
    if (students > nums.size()) return -1; // More students than books

    int start = 0; // Minimum pages
    int end = 0; // Maximum pages 



    for (int i = 0; i < nums.size(); i++) {

        start = max(start, nums[i]); // Find the maximum book pages
        end += nums[i]; // Total pages
    }
  

    
    int result = -1; // Initialize result

    while (start <= end) {
        int mid = start + (end - start) / 2; // Midpoint of current range

        // Check if mid can be a valid allocation
        if (isValid(nums, mid, students)) {
            result = mid; // Update result
            end = mid - 1; // Try for a smaller maximum
        } else {
            start = mid + 1; // Increase minimum limit
        }
    }

    return result; // Return the minimum possible maximum pages
}

int main() {
    vector<int> nums = {12, 34, 67, 90}; // Example book pages
    int students = 3; // Number of students

    int result = findPages(nums, students);
    if (result != -1) {
        cout << "Minimum number of pages: " << result << endl;
    } else {
        cout << "Not enough books for the students." << endl;
    }

    return 0;

}

