// =================================================================
//
// File: priority_queue.h
// Author: Fernando Josué Matute Soto
// Date: 23/10/22
// 
// =================================================================
#ifndef Priority_Queue_H_
#define Priority_Queue_H_

#include <string>
#include <sstream>
#include<iostream>
#include "exception.h"
#include "header.h"

template <class T> class List;

// =================================================================
// Definition of Priority_Queue class
// =================================================================
template <class T>
class Priority_queue
{
private:
    T   *data;
    unit size;
    unit counter;

    unit parent(unit) const;
    unit left(unit) const;
    unit right(unit) const;
    void pushDown(unit);
    void swap(unit, unit);

public:
    Priority_queue(unit); //Default constructor
    ~Priority_queue(); //Destructor
    bool empty() const;
    unit length() const;
    void add(T);
    T remove();
    void clear();
    string toString() const;
};

//Class Constructor
Priority_queue<T>::Priority_queue(unit size1){
    size = size1;
    data = new T[size];
    counter = 0;
}

//Class Destructor
Priority_queue<T>::~Priority_queue (){
    delete [] data;
    data = NULL;
    size = 0;
    counter = 0;
}

//empty() function returns a bool value 
//if the heap is empty or not
template <class T>
bool Priority_queue<T>::empty() const {
    return (counter == 0);
}

//lenght() returns the number of elements
//that are in the heap
template <class T>
unit Priority_queue<T>::length() const {
    return count;
}

//parent() returns the position of the
//element with the most priority
template <class T>
unit Priority_queue<T>::parent(unit pos) const {
    return (pos - 1) / 2
}

//left() returns the position of the
//element at the left
template <class T>
unit Priority_queue<T>::left(unit pos) const {
    return (pos * 2) + 1;
}

//right() returns the position of the
//element at the right
template <class T>
unit Priority_queue<T>::right(unit pos) const {
    return (pos * 2) + 2;
}

//swap() swaps two elements
template <class T>
void Priority_queue<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

//pushdown() places the element in the 
//correct position
template <class T>
void Priority_queue<T>::pushDown(uint pos) {
    uint le = left(pos);
    uint ri = right(pos);
    uint min = pos;

    if (le < count && data[le] < data[min]){
        min = le;
    }
    if (ri < count && data[ri] < data[min]){
        min = ri;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}

//add() adds an element, it is verified if is less
//than the father and adds it at the correct place
template <class T>
void Priority_queue<T>::add(T val) {
	uint pos;

	pos = count;
	count++;
	while(pos > 0 && val < data[parent(pos)]){
		data[pos]= data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

//remove() removes an element and the
//heap is rearranged
template <class T>
T Priority_queue<T>::remove() {
	if (empty()){
		throw NoSuchElement();
	}

	T aux = data[0];
	data[0] = data[--count]; // data[0] = data[count]; count--;
	pushDown(0);
	return aux;
}

//toString prints the representation
//of the heap
template <class T>
std::Priority_queue<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}

#endif /* LIST_H */