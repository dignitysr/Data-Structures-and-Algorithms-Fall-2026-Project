#include "Center.h"
#include <iostream>
int main() {
	Center testCenter;

	// randomly generating 1000 cars for the IDLE list
	testCenter.generateIdles();
	testCenter.getStatistics().setTotalCars(100);

	/*
	* Note: We were not provided with a concrete amount of bays
	* to allocate for each unit, so I chose 20 for each. If this choice
	* is incorrect, please have mercy on me...? I'll leave a variable to change
	* bay quantity just in case though.
	*/
	
	int bayCount = 20;
	testCenter.allocateBays(bayCount);
	UI* ui = new UI;

	int timestep = 0;
	while (testCenter.runSimulation(timestep)) {
		timestep++;
	
		
	}
	
	testCenter.getStatistics().setTotalSimulationTime(timestep);
	testCenter.printAll(ui);
	cout << testCenter.getStatistics().getTotalWaitingTime();
	
	string filename;
	
	cin >> filename;
	testCenter.saveStatistics(filename);
}