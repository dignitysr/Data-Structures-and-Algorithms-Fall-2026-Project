#include "Center.h"

static ServiceType getTypeFromBayPointer(Bay* bay);

void Center::loadFile() {
	int N_DU, N_MU, N_EU, N_WU, WB_Cap, M, VT, CID, PT, DD;
	ifstream InFile("input.txt");
	if (InFile.is_open()) {
		InFile >> N_DU;
		DiagBay DB;
		allocateNewBays(&DB, N_DU);
		InFile >> N_MU;
		MechBay MB;
		allocateNewBays(&MB, N_MU);
		InFile >> N_EU;
		ElecBay EB;
		allocateNewBays(&EB, N_EU);	
		InFile >> N_WU;
		InFile >> WB_Cap;
		WashBay WB(WB_Cap);
		allocateNewBays(&WB, N_WU, WB_Cap);	
		InFile >> Pcancel;
		InFile >> Presc;
		InFile >> M;
		centerStatistics.setTotalCars(M);
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

void Center::saveStatistics(string fileName)
{
	ofstream outFile(fileName+".txt");
	if (outFile.is_open()) {
		outFile << left;
		outFile << setw(10) << "FT" << setw(10) << "CID" << setw(10) << "PT" << setw(10) << "VT" << setw(10) << "TW" << setw(10) << "TS" << setw(10) << "State";
		outFile << endl;
		Car* car1, *car2;
		while (finishedCars.peek(car1) && cancelledCars.peek(car2)) {
			if (car1->getFT() >= car2->getFT()) {
				finishedCars.pop(car1);
				outFile << setw(10) << car1->getFT() << setw(10) << car1->getID() << setw(10) << car1->getPT() << setw(10) << car1->getVT() << setw(10) << car1->getTotalWaitingTime() << setw(10) << car1->getTotalServiceTime() << setw(10) << "F" << endl;
			}
			else {
				cancelledCars.pop(car2);
				outFile << setw(10) << car2->getFT() << setw(10) << car2->getID() << setw(10) << car2->getPT() << setw(10) << car2->getVT() << setw(10) << car2->getTotalWaitingTime() << setw(10) << car2->getTotalServiceTime() << setw(10) << "C" << endl;
			}
		}
		while (finishedCars.pop(car1)) {
			outFile << setw(10) << car1->getFT() << setw(10) << car1->getID() << setw(10) << car1->getPT() << setw(10) << car1->getVT() << setw(10) << car1->getTotalWaitingTime() << setw(10) << car1->getTotalServiceTime() << setw(10) << "F" << endl;
			
		}
		while (cancelledCars.pop(car2)) {
			outFile << setw(10) << car2->getFT() << setw(10) << car2->getID() << setw(10) << car2->getPT() << setw(10) << car2->getVT() << setw(10) << car2->getTotalWaitingTime() << setw(10) << car2->getTotalServiceTime() << setw(10) << "C" << endl;

		}
		float avgWaitingTime = float(float(centerStatistics.getTotalWaitingTime()) / centerStatistics.getTotalCars());
		float avgServiceTime = float(float(centerStatistics.getTotalServiceTime()) / centerStatistics.getTotalCars());
		int totalTimeStep = centerStatistics.getTotalSimulationTime();
		int totalCars = centerStatistics.getTotalCars();
		float avgWaitToServiceRatio = avgWaitingTime / avgServiceTime;
		float MBUti = float(float(centerStatistics.getMBUtilization()) / totalTimeStep)*100.0F;
		float WBUti = float(float(centerStatistics.getWBUtilization()) / totalTimeStep)*100.0F;
		float EBUti = float(float(centerStatistics.getEBUtilization()) / totalTimeStep)*100.0F;
		float DBUti = float(float(centerStatistics.getDBUtilization()) / totalTimeStep)*100.0F;
		float cancelRate = float(float(centerStatistics.getCancellationCount()) / totalCars) * 100.0F;
		float rescheduleRate = float(float(centerStatistics.getReschedulingCount()) / totalCars) * 100.0F;
		int FSAvgWT = centerStatistics.getFSTotalWaitingTime() / centerStatistics.getFScount();
		int SSAvgWT = centerStatistics.getSSTotalWaitingTime() / centerStatistics.getSScount();
		float latencyReduction = float(float(SSAvgWT - FSAvgWT) / SSAvgWT) * 100.0F;

		outFile << "------------------------Statistics---------------------------------------" << endl;
		outFile << "Total Simulation Time = " << totalTimeStep<< "|Total Cars = " << totalCars << endl;
		outFile << "Avg Waiting Time(TW) = " <<avgWaitingTime << " timesteps | Avg Service Time(TS) = " << avgServiceTime << " timesteps" << endl;
		outFile << "Average Wait - to - Service Ratio : " << avgWaitToServiceRatio << "%" << endl;
		outFile << "Bay Utilization : MB = " << MBUti << "%, WB = " << WBUti << "%, EB = " << EBUti << "%, DB = " << DBUti << "% " << endl;
		outFile << "Cancellation Rate = " << cancelRate << "% | Rescheduling Rate = " << rescheduleRate << "% " << endl;
		outFile << "Flexible Sequence(FS) Average WT : " << FSAvgWT << " timesteps" << endl;
		outFile << "Strict Sequence(SS) Average WT : " << SSAvgWT << " timesteps" << endl;
		outFile << latencyReduction << "% latency reduction via FS" << endl;
		outFile.close();

	}

	
	




		
		
		


}

void Center::Check_finished_Diagnosis_and_generate_the_service_list(int currentTimestep)
{
	Car* finishedCars;
	int finishedTime;
	while (diagCars.peek(finishedCars, finishedTime) && finishedTime==-currentTimestep) {
		diagCars.dequeue(finishedCars,finishedTime);
		finishedCars->generateRandomservices();
		Car* cancelledCar= handleCarAfterDiag(finishedCars, currentTimestep);
	}
}

bool Center::ReadytoDiag(Car* car, int currentTimestep)
{
	if (readyList.isEmpty() || freeDUList.isEmpty()) {
		return false;
	}
	DiagBay* bay;
	freeDUList.dequeue(bay);
	car->setBay(bay);
	car->setStatus(STATUS_DIAG);
	diagCars.enqueue(car, -(currentTimestep+car->getTotalServiceTime()));
	return true;
}

bool Center::assignServiceCar(Car* car, int currentTimestep)
{
   
}

bool Center::toFinishList(Car* car, int currentTimestep)
{
	return false;
}



int Center::distributeIdleCars(int currentTimestep) {
	int distributedCars = 0;
	while (!idleList.isEmpty()) {
		Car* car = nullptr;
		idleList.peek(car);
		int VT = car->getVT();

		if (VT != currentTimestep) return;

		idleList.dequeue(car);
		distributedCars++;

		if (VT == car->getPT()) {
			car->setStatus(STATUS_REDY);
			onTimeCount++;
			readyList.enqueue(car);
		}
		else if (VT > car->getPT()) {
			car->setStatus(STATUS_LATE);
			car->setCountOnArrival(onTimeCount);
			lateList.enqueue(car);
		}
		else {
			car->setStatus(STATUS_ERLY);
			earlyList.enqueue(car, -car->getPT());
		}
	}

	return distributedCars;
}

void Center::handleEarlyCars(int currentTimestep, int distributedCars) {
	if (readyList.isEmpty() && distributedCars == 0) {
		for (int i = 0; i < 3; i++) {
			Car* car = nullptr;
			int _ = 0;
			earlyList.dequeue(car, _);

			if (!car) return;

			car->setStatus(STATUS_REDY);
			onTimeCount++;
			readyList.enqueue(car);
		}
	}

	Car* car = nullptr;
	int VT = 0;
	while (earlyList.peek(car, VT) && car && VT == currentTimestep) {
		earlyList.dequeue(car, VT);

		car->setStatus(STATUS_REDY);
		onTimeCount++;
		readyList.enqueue(car);

		car = nullptr;
		VT = 0;
	}
}

void Center::handleLateCars(int currentTimestep) {
	Car* cancelledCar = lateList.cancelRandomCar(Pcancel); //cancels a late car randomly if it meets the probability
	if (cancelledCar) { cancelCar(cancelledCar, currentTimestep); cancelledCar->setStatus(STATUS_CNCL); }
	Car* car = nullptr;
	int carsTransferred = 0;
	while (lateList.peek(car) && car->getCountOnArrival() >= onTimeCount) {
		if (carsTransferred == 2) return;
		lateList.dequeue(car);

		car->setStatus(STATUS_REDY);
		onTimeCount++;
		readyList.enqueue(car);

		car = nullptr;
		carsTransferred++;
	}
}
Car* Center::handleCarAfterDiag(Car* car, int currentTimestep) {
	if (rand() % 100 < Pcancel) {
		cancelCar(car, currentTimestep);
		car->setStatus(STATUS_CNCL);
		return car;
	}
	return nullptr;
}



bool Center::runSimulation(int currentTimestep) {
	int distributedCars = distributeIdleCars(currentTimestep);
	handleEarlyCars(currentTimestep, distributedCars);
	handleLateCars(currentTimestep);
}

bool Center::runTestSimulation(int currentTimestep) {

	if (cancelledCars.getCount() + finishedCars.getCount() == 1000) {
		return false;
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
				cancelCar(diagCar, currentTimestep);
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
			if (car) {
				if (assignToRandomBay(car, currentTimestep)) {mechWaitingList.dequeue(car); car->setStatus(STATUS_SERV);}
				else car->setStatus(STATUS_WAIT);
			}
		}
		if (!freeWUList.isEmpty()) {
			Car* car = nullptr;
			washWaitingList.peek(car);
			if (car) {
				if (assignToRandomBay(car, currentTimestep)) {washWaitingList.dequeue(car); car->setStatus(STATUS_SERV);}
				else car->setStatus(STATUS_WAIT);
			}
		}
		if (!freeEUList.isEmpty()) {
			Car* car = nullptr;
			elecWaitingList.peek(car);
			if (car) {
				if (assignToRandomBay(car, currentTimestep)) {elecWaitingList.dequeue(car); car->setStatus(STATUS_SERV);}
				else car->setStatus(STATUS_WAIT);
			}
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

	return true;
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


static ServiceType getTypeFromBayPointer(Bay* bay) {
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

void Center::allocateNewBays(Bay* bay, int number, int cap)
{
	if (dynamic_cast<MechBay*>(bay)) {
		for (int i = 0;i < number;i++) {
			MechBay* dummy = new MechBay();
			freeMUList.enqueue(dummy);
		}
	}
	else if (dynamic_cast<WashBay*>(bay)) {
		for (int i = 0;i < number;i++) {
			WashBay* dummy = new WashBay(cap);
			freeWUList.enqueue(dummy);
		}
	}
	else if (dynamic_cast<ElecBay*>(bay)) {
		for (int i = 0;i < number;i++) {
			ElecBay* dummy = new ElecBay();
			freeEUList.enqueue(dummy);
		}
	}
	else if (dynamic_cast<DiagBay*>(bay)) {
		for (int i = 0;i < number;i++) {
			DiagBay* dummy = new DiagBay();
			freeDUList.enqueue(dummy);
		}
	}
}

void Center::printAll(UI* X)
{
	X->printQueue(idleList);
	X->printSpacing();
	X->printPriQueue(earlyList);
	X->printSpacing();
	X->printQueue(lateList);
	X->printSpacing();
	X->printQueue(readyList);
	X->printSpacing();
	X->printQueue(freeDUList);
	X->printSpacing();
	X->printPriQueue(diagCars);
	X->printSpacing();
	X->printQueue(mechWaitingList);
	X->printSpacing();
	X->printQueue(elecWaitingList);
	X->printSpacing();
	X->printQueue(washWaitingList);
	X->printSpacing();
	X->printQueue(freeMUList);
	X->printSpacing();
	X->printQueue(freeEUList);
	X->printSpacing();
	X->printQueue(freeWUList);
	X->printSpacing();
	X->printPriQueue(serviceCars);
	X->printSpacing();
	X->printStack(cancelledCars);
	X->printSpacing();
	X->printStack(finishedCars);
	X->printSpacing();
}

void Center::generateIdles() {
	for (int i = 0; i < 1000; i++) {
		Car* car = new Car(rand() % 1000, rand() % 50, (rand() % 50) + 50, 3);

		idleList.enqueue(car);
		car->setStatus(STATUS_IDLE);
	}
}