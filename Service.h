#pragma once
#include "DEFS.h"
class Service
{
	private:
		ServiceType serviceType;
		int duration;
	public:
		Service();
		Service(ServiceType st, int duration_);
		int getDuration();
		ServiceType getServiceType();
};