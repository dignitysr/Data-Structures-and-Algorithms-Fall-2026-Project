#pragma once
#include <iostream>
#include <string>
#include "LinkedQueue.h"
#include "DEFS.h"

class Bay
{
	BayType type;
	int maxcapicity;
	int carcount;

public:
	Bay(BayType T, int capicity, int count) {
		type = T;
		maxcapicity = capicity;
		carcount = count;
	}

	void settype(BayType typee ) {
		type = typee;
	}
	void setmaxcapicity( int x) {
		maxcapicity = x;
	}
	void setcarcount(int x) {
		carcount = x;
	}

	int getcapicity() {
		return maxcapicity;
	}
	int getcarcount() {
		return carcount;
	}
	BayType getype() {
		return type;
	}

};

