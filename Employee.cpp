//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jun 01 2021
//==============================================
// Workshop 02 Part 1
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {


    int noOfEmployees = noOfRecords();

    struct Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& STemp) {
        bool ok = false;
        char name[128];
        if (read(STemp.m_empNo) && read(STemp.m_salary) && read(name)) {
            STemp.m_name = new char[strlen(name) + 1];
                strcpy(STemp.m_name, name);
                ok = true;
            }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees && load(employees[i]); i++) 
                if (i != noOfEmployees) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                }

              else {
                  ok = true;
              }
               closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
            }  
      return ok;
 }

   // TODO: Implementation for the display functions go here
   void display() {
       int i;
       cout << "Employee Salary report, sorted by employee number" << endl
           << "no - Empno, Name, Salary" << endl
           << "------------------------------------------------" << endl;

       sort();
       for (i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << " ";
           display(employees[i]);
       }
   }
   void display(const Employee& employee) {

       cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
   }
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i;
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
     
   }
}

