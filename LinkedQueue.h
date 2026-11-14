#pragma once
#include "Node.h"
#include "QueueADT.h"

#include <iostream>
using namespace std;


template <typename T>
class LinkedQueue :public QueueADT<T>
{
protected:  //in case you need to inherit for the project	
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedQueue();

	//copy constructor
	LinkedQueue(const LinkedQueue<T>& LQ);
};
