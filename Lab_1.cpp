//
//
// Lab_1.cpp : 
// 
// Start with the following program employee record simple database:
// 
// Assignment:
// Part 1: Implementation
// Add a main menu to manage the employees data, which will include a choice of: 
// 1) Access employee record based on employee ID only (can be the index of the array, you may not to perform asearch, this is called Hashing 
// 2) Add an employee to the database
// 3) Delete an employee (delete the index), if an ID is available use it for the new employee

// Part 2: Report
// Provide program run snapshots and data validation in a report
// Upload your full lab to CANVAS   
//

// The above items are only suggestions, you can come up with your own design, 
// At minimum you should be able to perform the above programming steps.
// Lab grade will be based on programming creativity also.
//




#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Employee Class Declaration

class Employee
{
private:
    string name;        // Employee's name
    int idNumber;       // ID number
    string department;  // Department name
    string position;    // Employee's position

public:
    // Constructors
    Employee(string, int, string, string);
    Employee();

    // update methods
    void setName(string n)
    {
        name = n;
    }

    void setIdNumber(int i)
    {
        idNumber = i;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    void setPosition(string p)
    {
        position = p;
    }

    // Accessors
    string getName()
    {
        return name;
    }

    int getIdNumber()
    {
        return idNumber;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }
};

// Constructor #1
Employee::Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

// Constructor #3, default constructor
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

// display menu and return menu selection
int displayMenu() {
    int menu;
    cout << "~~~~~Menu~~~~~\n";
    cout << "1. Access Employee Record by Index\n";
    cout << "2. Add Employee\n";
    cout << "3. Delete Employee by Index\n";
    cout << "4. Exit Program\n";
    cout << "Enter number according to your menu choice: ";
    cin >> menu;
    cout << endl;
    return menu;
}

// Function prototype
void displayEmployee(Employee);

// function to add employee by ID
void addEmployee(vector<Employee>& employees) {
    string name;
    int id;
    string department;
    string position;
    
    // take name as input with space between first and last
    cout << "Enter New Employee Name: ";
    cin.ignore();
    getline(cin, name);
    // input validation looped
    while (true) {
        cout << "Enter New Employee ID: ";
        cin >> id;
        employees.resize(id + 1);
        if (id < 1 || id == employees[id].getIdNumber()) {
            cout << "Error: Invalid ID value.\n\n";
            continue;
        }
        else
            break;        
    }
    // department and position allowing for space characters
    cout << "Enter New Employee's Department: ";
    cin.ignore();
    getline(cin, department);
    cout << "Enter New Employee's Position: ";
    getline(cin, position);
    
    //enter employee at index = id; resizing the vector to fit the new highest index
    if (id >= employees.size()) {
        employees.resize(id + 1);
    }
    employees[id] = (Employee(name, id, department, position));
    cout << "\nEmployee Added.\n\n";
}

// function to delete employee by ID
void deleteEmployee(vector<Employee>& employees) {
    int remove;
    cout << "Enter Employee ID for employee deletion: ";
    cin >> remove;
    cout << endl;
    // input validation
    if (remove < 0 || remove >= employees.size() || employees[remove].getIdNumber() == 0) {
        cout << "Error: Invalid ID value.\n\n";
    }
    else {
        employees[remove] = Employee();
        cout << "Employee Deleted.\n\n";
    }
}

// function to search for employee
void searchEmployee(vector<Employee>& employees) {
    int search;
    cout << "Enter Employee ID to view record: ";
    cin >> search;
    cout << endl;
    // input validation
    if (search >= employees.size() || search < 1 || employees[search].getIdNumber() == 0) {
        cout << "Error: Invalid ID value.\n\n";
    }
    else {
        cout << "Employee info:\n";
        displayEmployee(employees[search]);
    }
}

// Driver program to demonstrate the class
int main()
{
    // Create an Employee object based on the current constructor.
    Employee Albert("Albert Smith", 1, "Executive", "President");
    Employee John("John Snow", 2, "Cyber Security", "Manager");

    // Vector of employee objects to allow for changes
    vector<Employee> employees;
    employees.resize(3);
    employees[1] = Albert;
    employees[2] = John;

    //Loops the menu interface until 
    int c = 0;
    while (c != 4) {
        c = displayMenu();
        switch (c) {
        // Search and display employee info
        case 1:
            searchEmployee(employees);
            break;
        // Add employee
        case 2:
            addEmployee(employees);
            break;
        // delete employee
        case 3:
            deleteEmployee(employees);
            break;
        //exit program <-> exit while loop
        case 4:
            cout << "Exiting program...\n";
            break;
        }
    }
    return 0;
}

//**************************************************
// The displayEmployee function displays the data  *
// in the Employee object passed as an argument.   *
//**************************************************

void displayEmployee(Employee e)
{
    cout << "Name: " << e.getName() << endl;
    cout << "ID Number: " << e.getIdNumber() << endl;
    cout << "Department: " << e.getDepartment() << endl;
    cout << "Position: " << e.getPosition() << endl << endl;
}