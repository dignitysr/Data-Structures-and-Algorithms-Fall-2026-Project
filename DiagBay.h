#pragma once
#include "Bay.h"

class DiagBay:public Bay
{
public:
	DiagBay() {
		settype(MU);
		setmaxcapicity(1);
		setcarcount(0);

	}
};

