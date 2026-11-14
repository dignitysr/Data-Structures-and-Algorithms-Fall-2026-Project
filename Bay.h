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


	void settype(BayType typee ) {
		type = typee;
	}
	void setmaxcapicity( int x) {
		maxcapicity = x;
	}
	void setcarcount(int x) {
		carcount = x;
	}


};

