#pragma once
#include "Bay.h"
class MechBay:public Bay
{
public:
	MechBay() {
		settype(MU);
		setmaxcapicity(1);
		setcarcount(0);
		
	}


};

