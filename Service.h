#pragma once
#include "DEFS.h"
class Service
{
	ServiceType servicetype;
	int duration;
public:
	Service(){}
	Service(ServiceType st, int duration_) {
		servicetype = st;
		duration = duration_;
	}
	int getduration() {
		return duration;
	}
	ServiceType getservicetype() {
		return servicetype;
	}
};