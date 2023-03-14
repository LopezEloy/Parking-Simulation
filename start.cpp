#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "parkingLot.h"
#include "Admin.h"

#include "ManagementEmployee.h"



using namespace std;

void start()
{
    vector<parkingLot> parkLots;
    vector<ManagementE> manemps; // management employees
    vector<Admin> admins;



    Admin tempAdmin;
    ManagementE tempMgmt;
    parkingLot tempLot;

    int numLots;
    int numReg;
    int numMot;
    int numDis;

    string inputName;
    string adminFile;
    string mgmtFile;
    string userFile;

    cout << "Enter file name: ";
    getline(cin, inputName);

    ifstream inputStream;
    inputStream.open(inputName);

    if(inputStream.fail()){
        cout << "\nError opening input file.\n";
    }

    inputStream >> numLots;

    while(numLots > 0){
        inputStream >> numReg;
        inputStream >> numMot;
        inputStream >> numDis;
        tempLot = parkingLot(numReg, numMot, numDis);
        parkLots.push_back(tempLot);
        numLots--;
    }

    for(int i = 0; i < parkLots.size(); i++){
	cout << "Parking lot number: " << i + 1 << endl
	     << "Number of parking space: " << parkLots[i].totalSpaces << endl
	     << "Number of regular parking space: " << parkLots[i].regularSpaces << endl
	     << "Number of motorcycle space: " << parkLots[i].motorcycleSpaces << endl
	     << "Number of disibility space: " << parkLots[i].disibilitySpaces << endl
	     << "Parking space layout is shown below.\n";
	parkLots[i].printLayout();
    }

    inputStream >> adminFile;
    inputStream >> mgmtFile;
    inputStream >> userFile;
    inputStream.close();

    ifstream adminStream;
    ifstream mgmtStream;
    ifstream userStream;

    adminStream.open(adminFile);
    mgmtStream.open(mgmtFile);
    userStream.open(userFile);

    if(inputStream.fail()){
        cout << "\nError opening input file.\n";
    }

    if(inputStream.fail()){
        cout << "\nError opening input file.\n";
    }

    if(inputStream.fail()){
        cout << "\nError opening input file.\n";
    }

    while(!adminStream.eof()){
        getline(adminStream,tempAdmin.adminEmpName,',');
        getline(adminStream,tempAdmin.adminEmpID,',');
        getline(adminStream,tempAdmin.adminEmpPass);
	if(adminStream.eof()){break;}
	admins.push_back(tempAdmin);
    }
    adminStream.close();

    cout << "\nAll Administrative Employee Information\n";
    cout << setfill('-') << setw(40) << "-\n";
    cout << setfill(' ') << setw(18) << "Name" << setw(18) << "ID\n";
    cout << setfill('-') << setw(36) << "-\n" << setfill(' ');
    for(int i = 0; i < admins.size(); i++){
	admins[i].printAdminInfo();
    }

    adminStream.close();
    mgmtStream.close();
    userStream.close();
}
