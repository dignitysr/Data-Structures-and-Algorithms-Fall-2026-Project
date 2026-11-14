#include "Bay.h"

void Bay::setType(BayType _type) {
	type = _type;
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

int Bay::getCapacity() {
	return maxCapacity;
}

int Bay::getcarCount() {
	return carCount;
}

BayType Bay::getType() {
	return type;
}