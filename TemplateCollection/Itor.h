#ifndef _ITOR_
#define _ITOR_
#include <iostream>
using namespace std;

template <class Elem>
class Itor
{
public:
	virtual ~Itor(){};
	virtual void begin()const = 0;
	virtual const Elem& get()const =0;
	virtual bool hasNext() const = 0;
	virtual void next() const = 0;
};
template<class Elem>
ostream& operator <<(ostream & os, const Itor<Elem>& it)
{
	it.begin();
	while (it.hasNext())
	{
		os<<it.get()<<':';
		it.next();
	}
	os<<endl;
	return os;
}
#endif