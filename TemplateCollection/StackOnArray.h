//
//  StackOnArray.h
//  Bonus
//
//  Created by Anastasia 
//  Copyright (c) 2015 Anastasia. All rights reserved.
//
#ifndef SOARR
#define SOARR
#include "Array.h"
#include <string>
#include <cassert>
#include "Itor.h"
#include <iostream>
using namespace std;
template <class Elem>
class Stack;
template <class Elem>
class StackOnArr: public Stack <Elem>
{
public:
	StackOnArr();
	~StackOnArr();
	 class BadStack
    {
    private:
        string message;
    public:
        BadStack(const string& str ="unknown"):
        message(str)
        {
            return;
        };
        ~BadStack()
        {};
        void diagnose()
        {
            cerr << message << endl;
        };
    };
	 class Iterator: public Itor<Elem>
	 {
	 private:
		 StackOnArr & _toIterate;
		 mutable size_t _i;
	 public: 
		 Iterator(StackOnArr& queue):_i(queue.size() - 1), _toIterate(queue){};
		 ~Iterator(){};
		 virtual void begin()const
		 {
			 _i = _toIterate.size() - 1;
		 }
		 virtual const Elem& get()const
		 {
			 return (*_toIterate._allocator)[_i];
		 }
		 virtual bool hasNext() const
		 {
			 return _i>=0 && _i < 4294967295;
		 }
		 virtual void next() const
		 {
			 if(!hasNext()) throw new BadStack("");
			 --_i;
		 }
	 };
private:
	size_t _size;
    Array<Elem>* _allocator;
    void resize(const size_t times);
	virtual bool doEmpty() const
	{
	return _size == 0;
	}
	virtual size_t doSize() const{
	return _size;
	}
	virtual void doPop()
	{
		if(_size == 0) throw BadStack("Trying to access non-existing element");
		_size--;
		if(_size > 0 && _size == (*_allocator).size()/4) resize((*_allocator).size()/2);
		return;
	}
	virtual void doPush(const Elem& elem)
	{
		if(_size == (*_allocator).size()) resize(2 * (*_allocator).size());
		(*_allocator)[_size++] = elem;
	}
	virtual const Elem& doTop() const
	{
		if(_size == 0) throw BadStack("Trying to access non-existing element");
		return (*_allocator)[_size - 1];
	}
	StackOnArr(const StackOnArr&);
	StackOnArr& operator=(const StackOnArr&);

};
template <class Type>
StackOnArr<Type>::StackOnArr():
_size(0), _allocator(new Array<Type>(2)){}
template <class Type>
StackOnArr<Type>::~StackOnArr()
{
	_allocator = 0;
}
template <class Type>
void StackOnArr<Type>::resize(const size_t times)
{
    assert(times >= (*_allocator).size());
    Array<Type>* tempArr = new Array<Type>(times);
    for (size_t i(0); i < (*_allocator).size(); ++i) {
		(*tempArr)[i] = (*_allocator)[i];
    }
    delete  _allocator;
    _allocator = tempArr;
}
#endif