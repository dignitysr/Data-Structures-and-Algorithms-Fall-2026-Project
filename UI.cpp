#include "UI.h"

void UI::printQueue(LinkedQueue<Car*> &Q) {
	Car* x = nullptr;
	int co = Q.getCount();
	Q.peek(x);
	LinkedQueue<Car*> Q1;
	int count = 0;
	if (!x) return;
	if (x->getStatus()==STATUS_IDLE) {
		cout << co << " IDLE: ";
	}
	else if (x->getStatus() == STATUS_LATE) {
		cout << co << " LATE: ";
	}
	else if (x->getStatus() == STATUS_REDY) {
		cout << co << " READY: ";
	}
	else if (x->getStatus() == STATUS_WAIT) {
		cout << co << " WAITING: ";
	}
	while (Q.dequeue(x)) {
		if ((!x->getStatus() == STATUS_IDLE) || (count < 15)) cout << x;
		count++;
		Q1.enqueue(x);
	}
	while (Q1.dequeue(x)) {
		Q.enqueue(x);
	}
	cout << endl;
}
void UI::printQueue(LinkedQueue<MechBay*> &Q) {
	MechBay* x = nullptr;
	int co = Q.getCount();
	LinkedQueue<MechBay*> Q1;
	Q.peek(x);

	if (!x) return;
	cout << co << " MB Free: ";
	while (Q.dequeue(x)) {
		cout << x << " ";
		Q1.enqueue(x);
	}
	while (Q1.dequeue(x)) {
		Q.enqueue(x);
	}
	cout << endl;
}
void UI::printQueue(LinkedQueue<DiagBay*> &Q) {
	DiagBay* x = nullptr;
	int co = Q.getCount();
	Q.peek(x);
	LinkedQueue<DiagBay*>Q1;
	if (!x) return;
	cout << co << " Diag Bays: ";
	while (Q.dequeue(x)) {
		cout << x << " ";
		Q1.enqueue(x);
	}
	while (Q1.dequeue(x)) {
		Q.enqueue(x);
	}
	cout << endl;
}
void UI::printQueue(LinkedQueue<ElecBay*> &Q) {
	ElecBay* x = nullptr;
	int co = Q.getCount();
	Q.peek(x);
	LinkedQueue<ElecBay*>Q1;
	if (!x) return;
	cout << co << " EB Free: ";
	while (Q.dequeue(x)) {
		cout << x << " ";
		Q1.enqueue(x);
	}
	while (Q1.dequeue(x)) {
		Q.enqueue(x);
	}
	cout << endl;
}
void UI::printQueue(LinkedQueue<WashBay*> &Q) {
	WashBay* x = nullptr;
	int co = Q.getCount();
	Q.peek(x);
	LinkedQueue<WashBay*>Q1;
	if (!x) return;
	cout << co << " WB Free: ";
	while (Q.dequeue(x)) {
		cout << x << " ";
		Q1.enqueue(x);
	}
	while (Q1.dequeue(x)) {
		Q.enqueue(x);
	}
	cout << endl;
}

//template <typename T>
//void UI::printQueue(LinkedQueue<T> &Q)
//{
//		LinkedQueue<T> Q1;
//		T x;
//		int co=Q.getCount();
//		int num = 0;
//		Q.peek(x);
//			if (IDLEList* idle = dynamic_cast<IDLEList*>(x)) {
//				cout << co<<" IDLE: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//					if (num >= 15) {
//						break;
//					}
//				}
//			}
//			else if (LATEList* late = dynamic_cast<LATEList*>(x)) {
//				cout << co<<" LATE: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (WaitEU* eu = dynamic_cast<WaitEU*>(x)) {
//				cout <<co<< "EB Cars Waiting: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (WaitMU* mu = dynamic_cast<WaitMU*>(x)) {
//				cout <<co<< "MB Cars Waiting: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (WaitWU* wu = dynamic_cast<WaitWU*>(x)) {
//				cout << co << "WB Cars Waiting: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (DiagBay* Diag = dynamic_cast<DiagBay*>(x)) {
//				cout << co << " Free Diag Bays: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (MechBay* Mech = dynamic_cast<MechBay*>(x)) {
//				cout << co << " Free Mech Bays: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (ElecBay* Elec = dynamic_cast<ElecBay*>(x)) {
//				cout << co << " Free Elec Bays: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (WashBay* Wash = dynamic_cast<WashBay*>(x)) {
//				cout << co << " Free Wash Bays: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//			else if (Car* car = dynamic_cast<Car*>(x)) {
//				cout << co << " REDY: ";
//				while (Q.dequeue(x)) {
//					Q1.enqueue(x);
//					cout << x;
//				}
//			}
//		
//		while (Q1.dequeue(x)) {
//			Q.enqueue(x);
//		}
//}

void UI::printStack(ArrayStack<Car*> &S)
{
	int count = S.getCount();
	Car* y = nullptr;
	S.peek(y);
	ArrayStack<Car*> S2;

	if (!y) return;
	if (y->getStatus() == STATUS_CNCL) {
		cout << count << " Cancelled: ";
	}
	else if (y->getStatus() == STATUS_FNSH) {
		cout << count << " DONE: ";
	}
	while (S.pop(y)) {
		cout << y;
		S2.push(y);
	}
	while (S2.pop(y)) {
		S.push(y);
	}
	cout << endl;
}

void UI::printPriQueue(PriorityQueue<Car*> &P)
{
	Car* w = nullptr;
	int _;
	P.peek(w, _);
	PriorityQueue<Car*> P2;
	if (w == nullptr) return;
	int count2 = P.getCount();
	int pri = 0;
	if (w->getStatus()== STATUS_ERLY) {
		cout << count2 << " ERLY: ";
	}
	else if (w->getStatus() == STATUS_DIAG) {
		cout << count2 << " Cars in Diag: ";
	}
	else if (w->getStatus() == STATUS_SERV) {
		cout << count2 << " Cars in Service: ";
	}
	while (P.dequeue(w,pri)) {
		cout << w;
		P2.enqueue(w, pri);
	}
	while (P2.dequeue(w, pri)) {
		P.enqueue(w, pri);
	}
	cout << endl;
}
int UI::getint()
{
	cout << "Enter 1 for interactive mode or 2 for silent mode: "<<endl;
	int x;
	cin >> x;
	if (x != 1 || x != 0) {
		cout << "Please input either 1 or 2" << endl;
		cin >> x;
	}
	return x;
	cout << endl;
}

void UI::printSpacing() {
	cout << endl << "=============================" << endl;
}

void UI::waitForInput()
{
	cout << "PRESS ENTER TO CONTINUE" << endl;
	cin.ignore();
	cin.get();
}