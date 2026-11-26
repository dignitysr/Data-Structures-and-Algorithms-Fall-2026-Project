#pragma once
#include "LinkedQueue.h"
#include"priQueue.h"
#include "Service.h"
#include"WAIT_EU.h"
#include"WAIT_MU.h"
#include"WAIT_WU.h"

class ServiceList: public LinkedQueue<Service*> {
	public:
		int getTotalServiceTime() const;
		Service* getfirstservice();
		void makeitflixable(WaitEU& eu, WaitMU& mu, WaitWU& wu);
};

