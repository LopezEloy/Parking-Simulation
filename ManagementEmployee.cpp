#include <iostream>
#include "ManagementEmployee.h"
#include <iomanip>
#include <iterator>

using namespace std;

ManagementE::ManagementE()
{
  this->employeeName = "empName";
  this->employeeID = "None";
  this->employeePassword = "empPass";
}

ManagementE::ManagementE(string empName, int empID, string empPass)
{
  this->employeeName = empName;
  this->employeeID = empID;
  this->employeePassword = empPass;
}

void ManagementE::printManagementInfo()
{
  cout << setw(18) << left << employeeName << setw(17) << right << employeeID << endl;
}
