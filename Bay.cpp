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

void Bay::decrementCount() {
	carCount--;
}

int Bay::getCapacity() {
	return maxCapacity;
}

int Bay::getCarCount() {
	return carCount;
}

BayType Bay::getType() {
	return type;
}