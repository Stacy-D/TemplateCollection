/*
*Stack
*@author Stacy
*/
#ifndef  STACK_H
#define  STACK_H

template <class Elem>
class Stack{
public:
	Stack(){};
	virtual ~Stack(){}
	bool empty() const{ return doEmpty();}
	size_t size() const{ return doSize();}
	 const Elem& top() const{ return doTop();}
	// get Element LIFO
	void pop() {doPop();}
	// add Element to the queue
	void push(const Elem& elem){ doPush(elem);}
private:
	virtual bool doEmpty() const = 0;
	virtual size_t doSize() const = 0;
	virtual void doPop() = 0;
	virtual const Elem& doTop() const = 0;
	virtual void doPush(const Elem& elem) = 0;
	Stack& operator=(const Stack&);
};
#endif
