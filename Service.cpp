#include "Service.h"

Service::Service(ServiceType st, int duration_) {
	serviceType = st;
	duration = duration_;
}

int Service::getDuration() {
	return duration;
}

ServiceType Service::getServiceType() {
	return serviceType;
}