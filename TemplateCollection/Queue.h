/*
*Queue
*@author Stacy
*/
#ifndef QUEUE_H
#define  QUEUE_H

template <class Elem>
class Queue{
public:
	Queue(){};
	virtual ~Queue(){}
	bool empty() const{ return doEmpty();}
	size_t size() const{ return doSize();}
	 const Elem& peek() const{ return doPeek();}
	// get Element FIFO
	void dequeue() {doDequeue();}
	// add Element to the queue
	void enqueue(const Elem& elem){ doEnqueue(elem);}
private:
	virtual bool doEmpty() const = 0;
	virtual size_t doSize() const = 0;
	virtual void doDequeue() = 0;
	virtual const Elem& doPeek() const = 0;
	virtual void doEnqueue(const Elem& elem) = 0;
	Queue& operator=(const Queue&);
};
#endif
