#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <typeinfo>
#include "Admins.h"
#include "Admin.h"
#include <iomanip>


using namespace std;


void Admins::AddAE(){

    Admin AEtempObj;
    string adminEmpName = "_";
    string adminEmpID = 0;
    string adminEmpPass = "_";

    // Creates randID and stores it as a string
    srand(time(NULL));
    int randID = rand()% 399 + 101;
    stringstream Stemp;
    Stemp << randID;
    Stemp >> AEtempObj.adminEmpID;

    cout << "Enter administrative employee name: "; cin.ignore(); getline(cin, AEtempObj.adminEmpName);

    cout << "Auto generated id for this administrative employee account is: " << adminEmpID;

    cout << "Set a password for this administrative employee account: "; cin >> AEtempObj.adminEmpPass;

    adminlist.push_back(AEtempObj);
    numAdmins++; cout <<"\n";
    cout << "Administrative employee entry is complete.\n";
}

void Admins::RemAE(){
    string AEID;
    char h; // just a char for input
    bool del;
    vector<Admin>::iterator it;
    int i = 0;
    cout << "Enter the ID of the AE you wish to remove: "; cin >> AEID;

    for (it = adminlist.begin(); it != adminlist.end(); ++it, ++i)
    {
      if(AEID == adminlist[i].adminEmpID){
        do{
          cout << "Do you wish to continue? ('Y' yes , 'N' no) |: "; cin >> h;
          toupper(h);
          if (h == 'Y' || h == 'y'){
            cout << endl;
            cout << "***** AE #" << AEID << " was just deleted *****\n";
            adminlist.erase(it);
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
          cout << "There is no ID on reccord that matches: \n" << AEID;
          break;
      }
    }
}

void Admins::ViewAllAE(){

    cout << "\nAll Administrative Employee Information\n";
    cout << setfill('-') << setw(40) << "-\n";
    cout << setfill(' ') << setw(18) << "Name" << setw(18) << "ID\n";
    cout << setfill('-') << setw(36) << "-\n" << setfill(' ');
    for(int i = 0; i < adminlist.size(); i++){
	adminlist[i].printAdminInfo();
    }
}

void Admins::SrchAE(){

    string AEID;
    vector<Admin>::iterator it;
    int i = 0;
    cout << "Enter the administrative employee's id: "; cin >> AEID;
    for (it = adminlist.begin(); it != adminlist.end(); ++it, ++i)
    {

    if (AEID == adminlist[i].adminEmpID) {
        cout << setfill('-') << setw(40) << "-\n";
        cout << setfill(' ') << setw(18) << "Name" << setw(18) << "ID\n";
        cout << setfill('-') << setw(36) << "-\n" << setfill(' ');
        adminlist[i].printAdminInfo(); cout << endl;
    }
    else{
        cout << "There is no AE with the following ID: " << AEID << endl;
        break;
    }
    }
}
Admins::Admins(ifstream &AEstream) {
    //numAdmins = 0;
    Admin AEtempObj;
    while(!AEstream.eof()){
        getline(AEstream,AEtempObj.adminEmpName,',');
        getline(AEstream,AEtempObj.adminEmpID,',');
        getline(AEstream,AEtempObj.adminEmpPass);
         if(AEstream.eof()) {break;}
            this->adminlist.push_back(AEtempObj);
    }
    AEstream.close();
}
