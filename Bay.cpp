#include "Bay.h"
void Bay::setType(BayType _type) {
	type = _type;
}

void Bay::setID(int ID)
{
	bayID = ID;
}



void Bay::setMaxCapacity(int x) {
	maxCapacity = x;
}

void Bay::setCarCount(int x) {
	carCount = x;
}

void Bay::incrementCount() {
	carCount++;
}

void Bay::decrementCount() {
	carCount--;
}

int Bay::getCapacity() {
	return maxCapacity;
}

int Bay::getID()
{
	return bayID;
}

int Bay::getCarCount() {
	return carCount;
}

BayType Bay::getType() {
	return type;
}

bool Bay::isBusy()
{
	return carCount == maxCapacity;
}

ostream& operator<<(ostream& os,const Bay* B)
{
	switch (B->type) {
	case DU:
		cout << "D" << B->bayID;
		break;
	case MU:
		cout << "M" << B->bayID;
		break;
	case EU:
		cout << "E" << B->bayID;
		break;
	case WU:
		cout << "W" << B->bayID;
		break;
	}
}
