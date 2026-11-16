#pragma once
#include "Bay.h"

class DiagBay: public Bay
{
	public:
		static int count;
		
		DiagBay();
		string getBayName() override;
};

