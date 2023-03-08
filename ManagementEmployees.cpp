#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <typeinfo>
#include "ManagementEmployees.h"
#include "ManagementEmployee.h"
#include <iomanip>


using namespace std;


void ManEmps::AddME()
{

    ManagementE MEtempObj;
    string employeeName = "None";
    string employeeID = 0;
    string employeePassword = "None";

    // Creates randID and stores it as a string
    srand(time(NULL));
    int randID = rand()% 399 + 101;
    stringstream Stemp;
    Stemp << randID;
    Stemp >> MEtempObj.employeeID;
/*
    Enter Management employee name: Manny
    Auto generated id for this Management employee account is: 365
    Set a password for this management employee account: Manage2
    management employee entry is complete.
*/
    cout << "Enter management employee name: "; cin.ignore(); getline(cin, MEtempObj.employeeName);

    cout << "Auto generated id for this management employee account is: " << employeeID;

    cout << "Set a password for this management employee account: "; cin >> MEtempObj.employeePassword;

    ManEmplist.push_back(MEtempObj);
    numManEmps++; cout <<"\n";
    cout << "Management employee entry is complete.\n";
}

void ManEmps::RemME()
{
    string MEID;
    char h; // just a char for input
    bool del;
    vector<ManagementE>::iterator it;
    int i=0;

    cout << "Enter the ID of the Management Employee you wish to remove: "; cin >> MEID;

    for (it=ManEmplist.begin();it!=ManEmplist.end();++it,++i) // why ++it,++i
    {
    if(MEID == ManEmplist[i].employeeID)
      {
        do{
          cout << "Do you wish to continue? ('Y' yes , 'N' no) |: "; cin >> h;
          toupper(h);
          if (h == 'Y' || h == 'y')
          {
            cout << endl;
            cout << "***** ME #" << MEID << " was just deleted *****\n";
            ManEmplist.erase(it);
            break;
          }
          else if(h == 'N' || h == 'n'){
            del = false;
            break;
          }
          else
          cout << "Incorect\n";
        }while(h != 'Y' || h != 'y' || h != 'N' || h != 'n');
      }
      else{
          cout << "There is no ID on reccord that matches: \n" << MEID;
          break;
      }
    }
}


void ManEmps::ViewAllME()
  {

    cout << "\nAll Management Employee Information\n";
    cout << setfill('-') << setw(40) << "-\n";
    cout << setfill(' ') << setw(18) << "Name" << setw(18) << "ID\n";
    cout << setfill('-') << setw(36) << "-\n" << setfill(' ');
    for(int i = 0; i < ManEmplist.size(); i++)
    {
	     ManEmplist[i].printManagementInfo();
    }

}

void ManEmps::SearchME()
{

    string MEID;
    vector<ManagementE>::iterator it;
    int i=0;
    cout << "Enter the management employee's ID: "; cin >> MEID;
    for (it = ManEmplist.begin(); it != ManEmplist.end(); ++it, ++i)
      {

      if (MEID == ManEmplist[i].employeeID)
      {
          cout << setfill('-') << setw(40) << "-\n";
          cout << setfill(' ') << setw(18) << "Name" << setw(18) << "ID\n";
          cout << setfill('-') << setw(36) << "-\n" << setfill(' ');
          ManEmplist[i].printManagementInfo(); cout << endl;
      }
      else{
          cout << "There is no AE with the following ID: " << MEID << endl;
          break;
      }
      }
  }

ManEmps::ManEmps(ifstream &MEstream)
{
    //numAdmins = 0;
    ManagementE MEtempObj;
    while(!MEstream.eof()){
        getline(MEstream,MEtempObj.employeeName,',');
        getline(MEstream,MEtempObj.employeeID,',');
        getline(MEstream,MEtempObj.employeePassword);
         if(MEstream.eof()) {break;}
            this->ManEmplist.push_back(MEtempObj);
    }
    MEstream.close();
}
