#include "DiagBay.h"
int DiagBay::count = 0;
		
DiagBay::DiagBay() {
	setType(DU);
	setMaxCapacity(1);
	setCarCount(0);
	DiagBay::count++;
		setID(DiagBay::count);
}

string DiagBay::getBayName() {return "Diag Bay"; }