#include "Queue.hpp"

#include <iostream>

using namespace std;

int main(){
	ArrayQueue<int> arrayQueue;
	Queue<int> listQueue;
	
	cout << "Array Queue:" << endl;
	for(int f0 = 0, f1 = 1, fn = f1; f0 < 4181; fn = f1, f1 = f0+f1, f0 = fn){
		arrayQueue.enqueue(f0);
	}
	while(!arrayQueue.isEmpty()){
		cout << arrayQueue.dequeue() << " ";
	}
	cout << endl;
	
	cout << "List Queue:" << endl;
	for(int f0 = 0, f1 = 1, fn = f1; f0 < 4181; fn = f1, f1 = f0+f1, f0 = fn){
		listQueue.enqueue(f0);
	}
	while(!listQueue.isEmpty()){
		cout << listQueue.dequeue() << " ";
	}
	cout << endl;
	
	return 0;
}