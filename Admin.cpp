#include "Admin.h"
#include <iostream>
#include <iomanip>
#include <iterator>


using namespace std;

Admin::Admin()
{
    this->adminEmpName = "AEname";
    this->adminEmpID = "AEID";
    this->adminEmpPass = "AEpass";

}

Admin::Admin(string AEname, string AEID, string AEpass)
{
    this->adminEmpName = AEname;
    this->adminEmpID = AEID;
    this->adminEmpPass = AEpass;
}

void Admin::printAdminInfo(){
    cout << setw(18) << left << adminEmpName << setw(17) << right << adminEmpID << endl;
}
