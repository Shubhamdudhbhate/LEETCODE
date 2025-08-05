#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold CSV employee data
struct Employee {
    string name;
    float basic;
};

int main() {
    // -------------------- 1. WRITING TO A FILE --------------------
    ofstream outFile("myfile.txt"); // Creates or overwrites the file
    if (outFile.is_open()) {
        outFile << "Welcome to File Handling in C++.\n";
        outFile << "This file contains multiple types of data.\n";
        outFile.close();
        cout << "Data written to myfile.txt\n\n";
    } else {
        cout << "Error: Could not open file for writing.\n";
    }





    // -------------------- 2. APPENDING TO A FILE --------------------
    ofstream appendFile("myfile.txt", ios::app); // Open in append mode
    if (appendFile.is_open()) {
        appendFile << "This line is appended.\n";
        appendFile.close();
        cout << "Data appended to myfile.txt\n\n";
    } else {
        cout << "Error: Could not open file for appending.\n";
    }





    // -------------------- 3. READING LINE BY LINE --------------------
    ifstream readFile("myfile.txt");
    string line;
    if (readFile.is_open()) {
        cout << "Reading file line by line:\n";
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
        cout << endl;
    } else {
        cout << "Error: File not found while reading.\n";
    }





    // -------------------- 4. READING WORD BY WORD --------------------
    ifstream wordFile("myfile.txt");
    string word;
    if (wordFile.is_open()) {
        cout << "Reading file word by word:\n";
        while (wordFile >> word) {
            cout << word << endl;
        }
        wordFile.close();
        cout << endl;
    }




    // -------------------- 5. CHECK IF FILE EXISTS --------------------
    ifstream checkFile("myfile.txt");
    if (checkFile) {
        cout << "✅ myfile.txt exists.\n\n";
    } else {
        cout << "❌ myfile.txt does not exist.\n\n";
    }





    // -------------------- 6. READING CSV FILE (EMPLOYEE DATA) --------------------
    // Sample CSV file content (employee.csv):
    // Name,Basic
    // Shubham,30000
    // Aarti,40000
    // Ajay,25000

    ofstream sampleCSV("employee.csv");
    sampleCSV << "Name,Basic\n";
    sampleCSV << "Shubham,30000\n";
    sampleCSV << "Aarti,40000\n";
    sampleCSV << "Ajay,25000\n";
    sampleCSV.close();

    ifstream csvFile("employee.csv");
    string csvLine;
    vector<Employee> employees;

    getline(csvFile, csvLine); // skip header
    while (getline(csvFile, csvLine)) {
        stringstream ss(csvLine);
        string name, basicStr;
        getline(ss, name, ',');
        getline(ss, basicStr, ',');
        Employee emp;
        emp.name = name;
        emp.basic = stof(basicStr); // convert string to float
        employees.push_back(emp);
    }
    csvFile.close();



    cout << "📄 Employee Records from employee.csv:\n";
    for (auto emp : employees) {
        cout << "Name: " << emp.name << ", Basic: " << emp.basic << endl;
    }


    return 0;
}
