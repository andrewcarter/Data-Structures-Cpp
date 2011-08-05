#include "Stack.hpp"

#include <iostream>

using namespace std;

int main()
{
	Stack<int> intStack;
	Stack<int> fibStack;
	
	for(int f0 = 0, f1 = 1, fn = f1; f0 < 34; fn = f1, f1 = f0+f1, f0 = fn){
		intStack.push(f0);
	}	
	while(!intStack.isEmpty()){
		fibStack.push(intStack.pop());
	}
	while(!fibStack.isEmpty()){
		cout << fibStack.pop() << " ";
	}
	cout << endl;
	
	return 0;
}