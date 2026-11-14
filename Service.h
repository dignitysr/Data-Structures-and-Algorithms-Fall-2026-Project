#pragma once
#include "DEFS.h"
class Service
{
	private:
		ServiceType serviceType;
		int duration;
	public:
		Service(){}
		Service(ServiceType st, int duration_) {
			serviceType = st;
			duration = duration_;
		}
		int getDuration() {
			return duration;
		}
		ServiceType getServiceType() {
			return serviceType;
		}
};