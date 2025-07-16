#include <iostream>
#include <iomanip>
using namespace std;

// Convert fractional marks to grade
string marksToGrade(float marks) {
    if (marks >= 90.0) return "AA";
    else if (marks >= 80.0) return "AB";
    else if (marks >= 70.0) return "BB";
    else if (marks >= 60.0) return "BC";
    else if (marks >= 50.0) return "CC";
    else if (marks >= 45.0) return "CD";
    else if (marks >= 40.0) return "DD";
    else return "FF";
}

// Convert grade to grade point
int gradeToPoint(string grade) {
    if (grade == "AA") return 10;
    else if (grade == "AB") return 9;
    else if (grade == "BB") return 8;
    else if (grade == "BC") return 7;
    else if (grade == "CC") return 6;
    else if (grade == "CD") return 5;
    else if (grade == "DD") return 4;
    else return 0; // FF or invalid
}

int main() {
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    float marks;
    int credit;
    int totalCredits = 0;
    int totalPoints = 0;

    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << "Enter marks (can be fractional) and credit for subject " << i << ": ";
        cin >> marks >> credit;

        string grade = marksToGrade(marks);
        int point = gradeToPoint(grade);

        cout << "Subject " << i << " Grade: " << grade << " (Grade Point: " << point << ")\n";

        totalPoints += point * credit;
        totalCredits += credit;
    }

    float sgpa = (float)totalPoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nYour SGPA is: " << sgpa << endl;

    return 0;
}
