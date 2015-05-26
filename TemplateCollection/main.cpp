#include <iostream>
using namespace std;
#include "Itor.h"
#include "QueueOnArray.h"
#include "Queue.h"
#include "StackOnArray.h"
#include "Stack.h"
#include "Array.h"
#include <string>

int main(void){
	QueueOnArr<double> queue;
	queue.enqueue(4);
	cout<<"Add 4"<<endl;
	queue.enqueue(5.67);
	cout<<"Add 5.67"<<endl;
	queue.enqueue(54);
	cout<<"Add 54"<<endl;
	queue.enqueue(55.67);
	cout<<"Add 55.67"<<endl;
	QueueOnArr<double>::Iterator iqar(queue);
	cout<<"Queue with double: "<<iqar;
	cout<<"Peek: "<<queue.peek()<<endl;
	queue.dequeue();
	cout<<"Peek after dequeue "<<queue.peek()<<"Plus size"<<queue.size()<<endl;
	//Stack
	StackOnArr<double> stack;
	stack.push(5.67);
	cout<<"Add 5.67"<<endl;
	stack.push(54);
	cout<<"Add 54"<<endl;
	stack.push(55.67);
	cout<<"Add 55.67"<<endl;
	StackOnArr<double>::Iterator isar(stack);
	cout<<stack.size()<<endl;
	cout<<"Stack with double: "<<isar;
	cout<<"Top: "<<stack.top()<<endl;
	stack.pop();
	cout<<"Top after pop "<<stack.top()<<" Plus size"<<stack.size()<<endl;
return 0;
}