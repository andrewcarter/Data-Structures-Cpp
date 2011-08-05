#include "BinarySearchTree.hpp"

#include <iostream>

using namespace std;

template<class T>
void buildBst(BST<T>& bst){
	bst.insert(42);
	bst.insert(28);
	bst.insert(56);
	bst.insert(11);
	bst.insert(33);
	bst.insert(72);
	bst.insert(99);
}

template<class T>
void evaluateSearch(const T* res){ 
	if(res != 0)
		cout << "Item was found in tree!" << endl;
	else
		cout << "Item was NOT found in tree ... :(" << endl;
}

int main() {
	BST<int> intBst;
	
	buildBst<int>(intBst);

	cout << "Preorder:" << endl;
	intBst.preorder();
	cout << endl;
	cout << "Inorder:" << endl;
	intBst.inorder();
	cout << endl;
	cout << "Postorder:" << endl;
	intBst.postorder();
	cout << endl;
	cout << "Bredth First (Top-Bottom, Left-Right):" << endl;
	intBst.bredthFirst();
	cout << endl;
	
	cout << "Searching For 33:" << endl;
	evaluateSearch<int>(intBst.search(33));
	cout << "Searching For 99:" << endl;
	evaluateSearch<int>(intBst.search(99));
	cout << "Searching 7:" << endl;
	evaluateSearch<int>(intBst.search(7));
	
	return 0;
}
