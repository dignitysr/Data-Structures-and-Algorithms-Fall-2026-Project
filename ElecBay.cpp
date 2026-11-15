#include "ElecBay.h"
int ElecBay::count = 0;

ElecBay::ElecBay() {
	setType(EU);
	setMaxCapacity(1);
	setCarCount(0);
	ElecBay::count++;
setID(ElecBay::count);
}