//
//  Array.h
//  Lab10
//
//  Created by Anastasia on 4/3/15.
//  Copyright (c) 2015 Anastasia. All rights reserved.
//

#ifndef Lab10_Array_h
#define Lab10_Array_h
#include <iostream>
using namespace std;
#include "Itor.h"
template<typename Type>
class Array
{
public:
    
    class BadIndex
    {
    private:
        size_t _index;
        string message;
    public:
        BadIndex(const string& str ="unknown",const size_t index = 0):
        _index(index),message(str)
        {
            return;
        };
        ~BadIndex(){};
        void diagnose()
        {
            cerr << message;
            if(_index!= 0 ) cerr<< ' ' <<_index;
            cerr << endl;
        };
    };
    explicit Array(const size_t size):
    _size(size),_content(new Type[_size])
    {
        return;
    }
    ~Array()
    {
        delete [] _content;
        _content = 0;
    }
    Type& operator[](const size_t index);
    const Type& operator[](const size_t index) const;
    size_t size() const;
private:
    const size_t _size;
    Type* _content;
    // Those operations and functions can not be defined for arrays
    Array(const Array&);
    Array& operator=(const Array&);
    bool operator==(const Array&) const;
};

template <typename Type>
Type&  Array<Type>::operator[](const size_t index)
{
    // no need to check index > 0 due to size_t type
    if(index >= size()) throw BadIndex("Index out Of Bound Exceptionn : ",index);
    return _content[index];
}
template <typename Type>
const Type&  Array<Type>::operator[](const size_t index) const
{
    if(index >= size()) throw BadIndex("Index out Of Bound Exceptionn : ",index);
    return _content[index];
}
template <typename Type>
size_t Array<Type>::size() const
{
    return _size;
}
template <typename Type>
ostream& operator<<(ostream& os, const Array<Type>& arr)
{
    char ch = ' ';
    os <<"Size of array "<<arr.size()<<':';
    for (size_t i(0); i < arr.size(); ++i)
    {
        os<<ch<<arr[i];
        if(ch == ' ') ch =',';
    }
    os << '.' <<endl;
    return os;
}
#endif
