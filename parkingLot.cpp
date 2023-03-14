#include "parkingLot.h"
#include <iostream>
#include <iomanip>

using namespace std;

parkingLot::parkingLot(int reg, int mot, int dis)
{
    regularSpaces = reg;
    motorcycleSpaces = mot;
    disibilitySpaces = dis;
    totalSpaces = reg + mot + dis;
}
parkingLot::parkingLot():regularSpaces(0),motorcycleSpaces(0),disibilitySpaces(0){};

void parkingLot::printLayout(){
    int count = 0;
    cout << setfill('-') << setw(4*(motorcycleSpaces + disibilitySpaces) + 3) << "\n|";
    while(count < motorcycleSpaces){
	cout << " M |";
	count++;
    }
    count = 0;
    while(count < disibilitySpaces){
	cout << " D |";
	count++;
    }
    count = 0;
    while(count < regularSpaces){
	if(count % ((motorcycleSpaces + disibilitySpaces)) == 0){
		cout << endl << "|";
	}
	cout << " R |";
	count++;
    }

    cout << endl << endl;
}

