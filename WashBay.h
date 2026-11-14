#pragma once
#include "Bay.h"

class WashBay:public Bay
{
public:
	WashBay(int x) {
		settype(MU);
		setmaxcapicity(x);
		setcarcount(0);

	}
};

