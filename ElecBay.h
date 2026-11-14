#pragma once
#include "Bay.h"

class ElecBay: public Bay
{ public:
	ElecBay() {
		settype(MU);
		setmaxcapicity(1);
		setcarcount(0);

	}
};

