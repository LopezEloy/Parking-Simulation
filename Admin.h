#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include <string>


using namespace std;

// 'AE' = "Administrative Employee"
class Admin
{
    public:

        string adminEmpName;
        string adminEmpID;
        string adminEmpPass;

	    Admin();
        Admin(string, string, string);
        void printAdminInfo();

};

#endif
