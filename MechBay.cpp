#include "MechBay.h"
int MechBay::count = 0;
MechBay::MechBay() {
	
	setType(MU);
	setMaxCapacity(1);
	setCarCount(0);
	MechBay::count++;
	setID(MechBay::count);
}