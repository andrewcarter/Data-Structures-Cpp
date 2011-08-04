#include "Queue.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Testing Array Queue..." << endl;
	ArrayQueue<int> arrayQueue;
	
	for(int f0 = 0, f1 = 1, fn = f1; f0 < 4181; fn = f1, f1 = f0+f1, f0 = fn){
		arrayQueue.enqueue(f0);
	}
	while(!arrayQueue.isEmpty()){
		cout << arrayQueue.dequeue() << endl;
	}
	
	cout << "Testing List Queue..." << endl;
	Queue<int> listQueue;
	
	for(int f0 = 0, f1 = 1, fn = f1; f0 < 4181; fn = f1, f1 = f0+f1, f0 = fn){
		listQueue.enqueue(f0);
	}
	while(!listQueue.isEmpty()){
		cout << listQueue.dequeue() << endl;
	}
	
	return 0;
}