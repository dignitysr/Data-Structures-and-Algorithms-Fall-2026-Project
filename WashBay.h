#pragma once
#include "Bay.h"

class WashBay: public Bay
{
	public:
		static int count;
		WashBay(int cap);
		string getBayName() override;
};

