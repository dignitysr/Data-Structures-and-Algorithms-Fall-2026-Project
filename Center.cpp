#include "Center.h"

void Center::loadFile() {
	int N_DU, N_MU, N_EU, N_WU, WB_Cap, M, VT, CID, PT, DD;
	ifstream InFile("input.txt");
	if (InFile.is_open()) {
		InFile >> N_DU;
		for (int i = 0;i < N_DU;i++) {
			DiagBay* dummy = new DiagBay();
			freeDUList.enqueue(dummy);
		}
		InFile >> N_MU;
		for (int i = 0;i < N_MU;i++) {
			MechBay* dummy = new MechBay();
			freeMUList.enqueue(dummy);
		}
		InFile >> N_EU;
		for (int i = 0;i < N_EU;i++) {
			ElecBay* dummy = new ElecBay();
			freeEUList.enqueue(dummy);
		}
		InFile >> N_WU;

		InFile >> WB_Cap;
		for (int i = 0;i < N_WU;i++) {
			WashBay* dummy = new WashBay(WB_Cap);
			freeWUList.enqueue(dummy);
		}
		InFile >> Pcancel;
		InFile >> Presc;

		InFile >> M;
		for (int i = 0;i < M;i++)
		{
			InFile >> VT;
			InFile >> CID;
			InFile >> PT;
			InFile >> DD;
			Car* dummy = new Car(CID, PT, VT, DD);
			idleList.enqueue(dummy);
		}
	}
}

bool Center::runTestSimulation(int currentTimestep) {

	if (idleList.isEmpty() && earlyList.isEmpty() && lateList.isEmpty() && readyList.isEmpty()) {
		return true;
	}

	// picking top 50 cars from the IDLE list and distributing them randomly
	for (int i = 0; i < 50; i++) {
		Car* car = nullptr;
		idleList.dequeue(car);

		if (!car) break;
		car->setStatus((CarStatus)((rand() % 3) + 1));

		switch (car->getStatus()) {
		case STATUS_ERLY:
			earlyList.enqueue(car, -car->getPT());
			break;
		case STATUS_LATE:
			lateList.enqueue(car);
			break;
		case STATUS_REDY:
			readyList.enqueue(car);
			break;
		}
	}

	// moving top 6 cars from the ERLY list to the REDY list
	for (int i = 0; i < 6; i++) {
		Car* car = nullptr;
		int _;
		earlyList.dequeue(car, _);
		if (!car) break;
		readyList.enqueue(car);
		car->setStatus(STATUS_REDY);
	}

	// cancel a random car and move it to cncl (10% chance)
	Car* cancelledCar = lateList.cancelRandomCar(10);
	if (cancelledCar) {cancelCar(cancelledCar, currentTimestep); cancelledCar->setStatus(STATUS_CNCL);}

	// moving top 6 cars from the LATE list to the REDY list
	for (int i = 0; i < 6; i++) {
		Car* car = nullptr;
		lateList.dequeue(car);
		if (!car) break;
		readyList.enqueue(car);
		car->setStatus(STATUS_REDY);
	}

	// moving cars to all free diagnosis bays
	DiagBay* freeDiagBay = nullptr;
	while (!readyList.isEmpty() && freeDUList.dequeue(freeDiagBay)) {
		freeDiagBay->incrementCount();
		Car* car = nullptr;
		readyList.dequeue(car);

		diagCars.enqueue(car, -(3 + currentTimestep));
		car->setBay(freeDiagBay);
		car->setStatus(STATUS_DIAG);
	}

	// moving cars which are done with their diagnoses
	Car* diagCar = nullptr;
	int finishTimestep;
	while (diagCars.peek(diagCar, finishTimestep)) {
		if (finishTimestep == -currentTimestep) {
			diagCars.dequeue(diagCar, finishTimestep);

			DiagBay* diagBay = (DiagBay*)diagCar->getBay();

			freeDUList.enqueue(diagBay);
			diagCar->setBay(nullptr);
			diagBay->decrementCount();

			if (rand() % 100 < 20) {
				cancelledCars.push(diagCar);
				continue;
			}

			switch ((ServiceType)(rand() % 3)) {
				case TYPE_MU:
					mechWaitingList.enqueue(diagCar);
					break;
				case TYPE_WU:
					washWaitingList.enqueue(diagCar);
					break;
				case TYPE_EU:
					elecWaitingList.enqueue(diagCar);
					break;
			}

			diagCar->setStatus(STATUS_WAIT);
		} else break;
	}

	//picking 6 cars from all WAIT lists and assigning them to bays
	for (int i = 0; i < 6; i++) {
		if (!freeMUList.isEmpty()) {
			Car* car = nullptr;
			mechWaitingList.peek(car);
			if (!car) continue;
			if (assignToRandomBay(car, currentTimestep)) mechWaitingList.dequeue(car);
			car->setStatus(STATUS_SERV);
		}
		if (!freeWUList.isEmpty()) {
			Car* car = nullptr;
			washWaitingList.peek(car);
			if (!car) continue;
			if (assignToRandomBay(car, currentTimestep)) washWaitingList.dequeue(car);
			car->setStatus(STATUS_SERV);
		}
		if (!freeEUList.isEmpty()) {
			Car* car = nullptr;
			elecWaitingList.peek(car);
			if (!car) continue;
			if (assignToRandomBay(car, currentTimestep)) elecWaitingList.dequeue(car);
			car->setStatus(STATUS_SERV);
		}
	}

	// finish bay utilization and return bays to their list if applicable, plus moving cars to appropriate lists
	Car* servCar = nullptr;
	while (serviceCars.peek(servCar, finishTimestep)) {
		if (finishTimestep == -currentTimestep) {
			serviceCars.dequeue(servCar, finishTimestep);

			Bay* bay = servCar->getBay();

			switch (getTypeFromBayPointer(bay)) {
				case TYPE_MU:
					freeMUList.enqueue((MechBay*)bay);
					break;
				case TYPE_WU:
					if (bay->getCarCount() == 3) freeWUList.enqueue((WashBay*)bay);
					break;
				case TYPE_EU:
					freeEUList.enqueue((ElecBay*)bay);
					break;
			}
			servCar->setBay(nullptr);
			bay->decrementCount();

			if (rand() % 100 < 40) {finishCar(servCar, currentTimestep); continue;}
			else {
				switch ((ServiceType)(rand() % 3)) {
					case TYPE_MU:
						mechWaitingList.enqueue(servCar);
						break;
					case TYPE_WU:
						washWaitingList.enqueue(servCar);
						break;
					case TYPE_EU:
						elecWaitingList.enqueue(servCar);
						break;
				}
			}
			servCar->setStatus(STATUS_WAIT);
		} else break; 
	}

	return false;
}

void Center::finishCar(Car* car, int currentTimestep) {
	car->setFT(currentTimestep);
	finishedCars.push(car);
	car->setStatus(STATUS_FNSH);
}

void Center::cancelCar(Car* car, int currentTimestep) {
	car->setCT(currentTimestep);
	cancelledCars.push(car);
	car->setStatus(STATUS_CNCL);
}

// Sorry...
ServiceType getTypeFromBayPointer(Bay* bay) {
	if (dynamic_cast<MechBay*>(bay)) return TYPE_MU;
	else if (dynamic_cast<WashBay*>(bay)) return TYPE_WU;
	else if (dynamic_cast<ElecBay*>(bay)) return TYPE_EU;
	else return TYPE_MU;
}

bool Center::assignToRandomBay(Car* car, int currentTimestep) {
	int value = rand() % 100;

	if (value < 60) return assignToMech(car, currentTimestep);
	else if (value < 90) return assignToElec(car, currentTimestep);
	else return assignToWash(car, currentTimestep);
}

bool Center::assignToWash(Car* car, int currentTimestep) {
	WashBay* freeWashBay = nullptr;
	freeWUList.peek(freeWashBay);

	if (!freeWashBay) return false;

	freeWashBay->incrementCount();

	if (freeWashBay->getCapacity() == freeWashBay->getCarCount()) freeWUList.dequeue(freeWashBay);

	serviceCars.enqueue(car, -(4 + currentTimestep));
	car->setBay(freeWashBay);
	return true;
}

bool Center::assignToMech(Car* car, int currentTimestep) {
	MechBay* freeMechBay = nullptr;
	freeMUList.dequeue(freeMechBay);

	if (!freeMechBay) return false;

	freeMechBay->incrementCount();

	serviceCars.enqueue(car, -(4 + currentTimestep));
	car->setBay(freeMechBay);
	return true;
}

bool Center::assignToElec(Car* car, int currentTimestep) {
	ElecBay* freeElecBay = nullptr;
	freeEUList.dequeue(freeElecBay);

	if (!freeElecBay) return false;

	freeElecBay->incrementCount();

	serviceCars.enqueue(car, -(4 + currentTimestep));
	car->setBay(freeElecBay);
	return true;
}

void Center::allocateBays(int count) {
	for (int i = 0; i < count; i++) {
		DiagBay* diagBay = new DiagBay();
		MechBay* mechBay = new MechBay();
		WashBay* washBay = new WashBay(3);
		ElecBay* elecBay = new ElecBay();

		freeDUList.enqueue(diagBay);
		freeMUList.enqueue(mechBay);
		freeWUList.enqueue(washBay);
		freeEUList.enqueue(elecBay);
	}
}

void Center::generateIdles() {
	for (int i = 0; i < 1000; i++) {
		Car* car = new Car(rand() % 1000, rand() % 50, (rand() % 50) + 50, 3);

		idleList.enqueue(car);
	}
}