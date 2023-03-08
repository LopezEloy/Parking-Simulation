#ifndef MANAGEMENTEMPLOYEE_H
#define MANAGEMENTEMPLOYEE_H

#include <vector>
#include <string>

using namespace std;

class ManagementE
{
  public:

    string employeeName;
    string employeeID;
    string employeePassword;

    ManagementE();
    ManagementE(string, int, string);

    void printManagementInfo();

};

#endif
