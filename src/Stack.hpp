#ifndef __STACK_HPP__
#define __STACK_HPP__
	
#include <vector>

//! Stack with STL vector as storage
template<class T, int size = 30>
class Stack {
public:
	Stack();
	Stack(int initCapacity);
	~Stack();
	T pop();
	T& peek();
	void push(const T& v);
	bool isEmpty();
	void clear();
	
private:
	std::vector<T> data;
};

template<class T, int size>
Stack<T, size>::Stack()
{
	data.reserve(size);
}

template<class T, int size>
Stack<T, size>::Stack(int initCapacity)
{
	data.reserve(initCapacity);
}

template<class T, int size>
Stack<T, size>::~Stack()
{
}

template<class T, int size>
T Stack<T, size>::pop()
{
	T el = data.back();
	data.pop_back();
	return el;
}

template<class T, int size>
T& Stack<T, size>::peek()
{
	return data.back();
}

template<class T, int size>
void Stack<T, size>::push(const T& v)
{
	data.push_back(v);
}

template<class T, int size>
bool Stack<T, size>::isEmpty()
{
	return data.empty();
}

template<class T, int size>
void Stack<T, size>::clear()
{
	data.clear();
}

#endif // __STACK_HPP__
