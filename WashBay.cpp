#include "WashBay.h"
int WashBay::count = 0;
		
WashBay::WashBay(int cap) {
	setType(WU);
	setMaxCapacity(cap);
	setCarCount(0);
	WashBay::count++;
		setID(WashBay::count);
}

string WashBay::getBayName() { return "Wash Bay"; }