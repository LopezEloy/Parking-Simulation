#ifndef MANAGEMENTEMPLOYEES_H
#define MANAGEMENTEMPLOYEES_H
#include <map>
#include <vector>
#include <iterator>
#include "ManagementEmployee.h"
using namespace std;


class ManEmps{
    public:
        int numManEmps;
        vector<ManagementE> ManEmplist;

// ME is Management Employee

        ManEmps(ifstream &MEstream);
        void AddME(); // Add an ME
        void RemME(); // Remove an ME
        void ViewAllME(); // Print all ME's
        void SearchME(); // Search for a specific ME
        void ChangePswrd(); // Change ME password
};
#endif
