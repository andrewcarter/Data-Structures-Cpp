#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <list>

// Queue implemented with array for storage
template <class T, int size = 100>
class ArrayQueue{
public:
	ArrayQueue() : first(-1),last(-1) {
	}
	
	void enqueue(T el);
	T dequeue();
	
	bool isFull(){
		return (first == 0 && last == size-1) || first == last+1;
	}
	
	bool isEmpty(){
		return first == -1;
	}

private:
	int first, last;
	T storage[size];
};

template <class T, int size>
void ArrayQueue<T, size>::enqueue(T el){
	if(isFull()){
		std::cout << "Queue is Full!" << std::endl;
	}
	
	if(last == -1 || last == size-1){
			storage[0] = el;
			last = 0;
			if(first == -1)
				first = 0;
	}
	else{
		storage[++last] = el;
	}
}

template<class T, int size>
T ArrayQueue<T, size>::dequeue(){
	T retEl;
	
	if(isEmpty()){
		std::cout << "Queue is Empty!" << std::endl;
	}
	else{
		retEl = storage[first];
		if (first == last){
			first = last = -1;
		}
		else if (first == size-1){
			first = 0;
		}
		else{
			first++;
		}
	}
	
	return retEl;
}

// Queue implemented with STL list for storage
template <class T>
class Queue{
public:
	Queue(){
	}

	void enqueue(T el){
		lst.push_back(el);
	}
	
	T dequeue(){
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	
	T& peekFront(){
		return lst.front();
	}
	
	T& peekBack(){
		return lst.back();
	}
	
	bool isEmpty() const {
		return lst.empty();
	}
	
	void clear(){
		lst.clear();
	}

private:
	std::list<T> lst;
};


#endif // __QUEUE_H__
