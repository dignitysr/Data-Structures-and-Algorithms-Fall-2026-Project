#pragma once
#pragma once
#include "priNode.h"


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class PriorityQueue
{
protected:  //in case you need to inherit for the project
    PriorityQueueNode<T>* head;
public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        PriorityQueueNode<T>* newNode = new PriorityQueueNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        PriorityQueueNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        PriorityQueueNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }
    int getCount() {
        PriorityQueue P2;
        int count = 0;
        int pri = 0;
        T x;
        while (dequeue(x,pri)) {
            P2.enqueue(x, pri);
            count++;
        }
        while (P2.dequeue(x, pri)) {
            enqueue(x, pri);
        }
        return count;
    }
    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
