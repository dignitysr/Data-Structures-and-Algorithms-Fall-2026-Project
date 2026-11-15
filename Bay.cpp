#include "Bay.h"

int Bay::count = 0;
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

ostream& operator<<(ostream& os,const Bay* c)
{
	cout << c->bayID;
}
