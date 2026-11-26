#include "Center.h"

int main() {
	Center testCenter;

	// randomly generating 1000 cars for the IDLE list
	testCenter.generateIdles();

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
		testCenter.printAll(ui);
		cout << "CURRENT TIMESTEP: " << timestep << endl;
		ui->waitForInput();
	}

	testCenter.printAll(ui);
}