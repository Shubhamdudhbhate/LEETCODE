#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip> // for setw, formatting

using namespace std;

struct Employee {
    string name;
    float basic;
    float hra;
    float da;
    float net;
};

// Function to read CSV and return vector of employees
vector<Employee> readCSV(const string& filename) {
    ifstream file(filename);
    vector<Employee> employees;
    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        stringstream ss(line);
        string name, basicStr;
        getline(ss, name, ',');
        getline(ss, basicStr, ',');
        Employee e;
        e.name = name;
        e.basic = stof(basicStr);
        e.hra = 0.2f * e.basic;
        e.da = 0.1f * e.basic;
        e.net = e.basic + e.hra + e.da;
        employees.push_back(e);
    }

    file.close();
    return employees;
}






// Write updated data with net salary to new CSV
void writeToCSV(const vector<Employee>& employees, const string& filename) {
    ofstream out(filename);
    out << "Name,Basic,HRA,DA,Net\n";
    for (const auto& e : employees) {
        out << e.name << "," << e.basic << "," << e.hra << "," << e.da << "," << e.net << "\n";
    }
    out.close();
}






// Find employee by name
void searchEmployee(const vector<Employee>& employees, const string& target) {
    bool found = false;
    for (const auto& e : employees) {
        if (e.name == target) {
            cout << "Found: " << e.name << ", Basic: " << e.basic << ", Net: " << e.net << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee " << target << " not found.\n";
    }
}






// Find min and max salary
void findMinMax(const vector<Employee>& employees) {
    if (employees.empty()) return;

    Employee minEmp = employees[0], maxEmp = employees[0];
    for (const auto& e : employees) {
        if (e.net < minEmp.net) minEmp = e;
        if (e.net > maxEmp.net) maxEmp = e;
    }

    cout << "💰 Employee with MIN salary: " << minEmp.name << " → " << minEmp.net << endl;
    cout << "💰 Employee with MAX salary: " << maxEmp.name << " → " << maxEmp.net << endl;
}








// Update salary of an employee
void updateSalary(vector<Employee>& employees, const string& name, float newBasic) {
    for (auto& e : employees) {
        if (e.name == name) {
            e.basic = newBasic;
            e.hra = 0.2f * e.basic;
            e.da = 0.1f * e.basic;
            e.net = e.basic + e.hra + e.da;
            cout << "✅ Salary updated for " << name << "\n";
            return;
        }
    }
    cout << "❌ Employee not found for update.\n";
}








// Print table of employees
void printSummary(const vector<Employee>& employees) {
    cout << left << setw(10) << "Name"
         << setw(10) << "Basic"
         << setw(10) << "HRA"
         << setw(10) << "DA"
         << setw(10) << "Net" << endl;
    cout << "-------------------------------------------\n";
    for (const auto& e : employees) {
        cout << left << setw(10) << e.name
             << setw(10) << e.basic
             << setw(10) << e.hra
             << setw(10) << e.da
             << setw(10) << e.net << endl;
    }
}










int main() {
    // Step 1: Create sample file
    ofstream file("employee.csv");
    file << "Name,Basic\n";
    file << "Shubham,30000\n";
    file << "Aarti,40000\n";
    file << "Ajay,25000\n";
    file << "Neha,35000\n";
    file << "Raj,27000\n";
    file.close();

    // Step 2: Read from CSV
    vector<Employee> employees = readCSV("employee.csv");

    // Step 3: Show full table
    cout << "📋 Employee Summary Table:\n";
    printSummary(employees);

    // Step 4: Search employee
    cout << "\n🔍 Search for an employee:\n";
    searchEmployee(employees, "Neha");

    // Step 5: Min and Max salary
    cout << "\n📊 Salary Range:\n";
    findMinMax(employees);

    // Step 6: Count total
    cout << "\n👥 Total Employees: " << employees.size() << endl;

    // Step 7: Update salary
    updateSalary(employees, "Ajay", 32000);

    // Step 8: Save updated data
    writeToCSV(employees, "updated_employees.csv");
    cout << "\n📁 Updated data saved to updated_employees.csv\n";

    return 0;
}
