//
//  QueueOnArray.h
//  Bonus
//
//  Created by Anastasia 
//  Copyright (c) 2015 Anastasia. All rights reserved.
//
#ifndef QOARR
#define QOARR
#include "Array.h"
#include <string>
#include <cassert>
#include "Itor.h"
#include <iostream>
using namespace std;
template <class Elem>
class Queue;
template <class Elem>
class QueueOnArr: public Queue <Elem>
{
public:
	QueueOnArr();
	~QueueOnArr();
	 class BadQue
    {
    private:
        string message;
    public:
        BadQue(const string& str ="unknown"):
        message(str)
        {
            return;
        };
        ~BadQue()
        {};
        void diagnose()
        {
            cerr << message << endl;
        };
    };
	 class Iterator: public Itor<Elem>
	 {
	 private:
		 QueueOnArr & _toIterate;
		 mutable size_t _i;
	 public: 
		 Iterator(QueueOnArr& queue):_i(0), _toIterate(queue){};
		 ~Iterator(){};
		 virtual void begin()const
		 {
			 _i = 0;
		 }
		 virtual const Elem& get()const
		 {
			 return (*_toIterate._allocator)[(_i+_toIterate._top)%(*_toIterate._allocator).size()];
		 }
		 virtual bool hasNext() const
		 {
			 return _i<_toIterate.size();
		 }
		 virtual void next() const
		 {
			 if(!hasNext()) throw new BadQue("");
			 ++_i;
		 }
	 };
private:
	size_t _size;
	size_t _last;
    Array<Elem>* _allocator;
    void resize(const size_t times);
    size_t _top;
	virtual bool doEmpty() const
	{
	return _size == 0;
	}
	virtual size_t doSize() const{
	return _size;
	}
	virtual void doDequeue()
	{
		if(_size == 0) throw BadQue("Trying to access non-existing element");
		_size--;
		_top++;
		if(_top == _size) _top = 0;
		if(_size > 0 && _size == (*_allocator).size()/4) resize((*_allocator).size()/2);
		return;
	}
	virtual void doEnqueue(const Elem& elem)
	{
		if(_size == (*_allocator).size()) resize(2 * (*_allocator).size());
		(*_allocator)[_last++] = elem;
		if(_last == (*_allocator).size()) _last = 0;
		_size++;
	}
	virtual const Elem& doPeek() const
	{
		if(_size == 0) throw BadQue("Trying to access non-existing element");
		return (*_allocator)[_top];
	}
	QueueOnArr(const QueueOnArr&);
	QueueOnArr& operator=(const QueueOnArr&);

};
template <class Type>
QueueOnArr<Type>::QueueOnArr():
_size(0),_last(0), _allocator(new Array<Type>(2)),_top(0){}
template <class Type>
QueueOnArr<Type>::~QueueOnArr()
{
	_allocator = 0;
}
template <class Type>
void QueueOnArr<Type>::resize(const size_t times)
{
    assert(times >= (*_allocator).size());
    Array<Type>* tempArr = new Array<Type>(times);
    for (size_t i(0); i < (*_allocator).size(); ++i) {
		(*tempArr)[i] = (*_allocator)[(_top + i)%(*_allocator).size()];
    }
    delete  _allocator;
    _allocator = tempArr;
    _top = 0;
	_last = _size;
}
#endif