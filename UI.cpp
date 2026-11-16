#include "UI.h"

template <typename T>
    void UI<T>::printQueue(LinkedQueue<T> &Q)
{
		LinkedQueue Q1;
		T x;
		int co=Q.getCount();
		int num = 0;
		Q.peek(x);
			if (IDLEList* idle = dynamic_cast<IDLEList*>(x)) {
				cout << co<<" IDLE: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
					if (num >= 15) {
						break;
					}
				}
			}
			else if (LATEList late = dynamic_cast<LATEList*>(x)) {
				cout << co<<" LATE: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (WaitEU* eu = dynamic_cast<WaitEU*>(x)) {
				cout <<co<< "EB Cars Waiting: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (WaitMU* mu = dynamic_cast<WaitMU*>(x)) {
				cout <<co<< "MB Cars Waiting: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (WaitWU* wu = dynamic_cast<WaitWU*>(x)) {
				cout << co << "WB Cars Waiting: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (DiagBay* Diag = dynamic_cast<DiagBay*>(x)) {
				cout << co << " Free Diag Bays: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (MechBay* Mech = dynamic_cast<MechBay*>(x)) {
				cout << co << " Free Mech Bays: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (ElecBay* Elec = dynamic_cast<ElecBay*>(x)) {
				cout << co << " Free Elec Bays: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (WashBay* Wash = dynamic_cast<WashBay*>(x)) {
				cout << co << " Free Wash Bays: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
			else if (Car* car = dynamic_cast<Car*>(x)) {
				cout << co << " REDY: ";
				while (Q.dequeue(x)) {
					Q1.enqueue(x);
					cout << x;
				}
			}
		
		while (Q1.dequeue(x)) {
			Q.enqueue(x);
		}
}
template <typename T>
void UI<T>::printStack(ArrayStack<T> &S)
{
	T y;
	S.peek(y);
	int count=S.getCount();
	if (Car* car= dynamic_cast<Car *>(y)) {
		if (car->getStatus() == STATUS_CNCL) {
			cout << count << " Cancelled: ";
		}
		else if (car->getStatus() == STATUS_FNSH) {
			cout << count << " DONE: ";
		}
		while (S.pop(y)) {
			cout << y;
		}
	}
		
	}
template <typename T>
void UI<T>::printPriQueue(PriorityQueue<T> &P)
{
	T w;
	P.peek(w);
	int count2 = P.getCount();
	if (Car* car = dynamic_cast<Car*>(y)) {
		if (car->getStatus()== STATUS_ERLY) {
			cout << count2 << " ERLY: ";
		}
		else if (car->getStatus() == STATUS_DIAG) {
			cout << count2 << " Cars in Diag: ";
		}
		else if (car->getStatus() == STATUS_SERV) {
			cout << count2 << " Cars in Service: ";
		}
		while (P.dequeue(w)) {
			cout << w;
		}
	}
}
template <typename T>
int UI<T>::getint()
{
	cout << "Enter 1 for interactive mode or 2 for silent mode: "<<endl;
	int x;
	cin >> x;
	if (x != 1 || x != 0) {
		cout << "Please input either 1 or 2" << endl;
		cin >> x;
	}
	return x;
}
