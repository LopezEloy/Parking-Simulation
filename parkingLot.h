#ifndef PARKINGLOT_H
#define PARKINGLOT_H

using namespace std;

class parkingLot
{
    public:
        parkingLot(int reg, int mot, int dis);
        parkingLot();
        void printLayout();
        int regularSpaces;
        int motorcycleSpaces;
        int disibilitySpaces;
	int totalSpaces;
};

#endif // PARKINGLOT_H
