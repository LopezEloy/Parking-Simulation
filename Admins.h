#ifndef ADMINS_H
#define ADMINS_H
#include <map>
#include <vector>
#include <iterator>
#include "Admin.h"
using namespace std;

// AdminOp = "Admin Operations"

class Admins{
    public:
        int numAdmins;
        vector<Admin> adminlist;

        //admin adminlist;
        // AE = "Administrative Employee"


        Admins(ifstream &AEstream);
        void AddAE(); // Add an AE
        void RemAE(); // Remove an AE
        void ViewAllAE(); // Print all AE's
        void SrchAE(); // Search for a specific AE
        void ChangePswrd(); // Change AE password
};
#endif
