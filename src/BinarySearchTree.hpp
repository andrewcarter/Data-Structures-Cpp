#ifndef __BINARYSEARCHTREE_HPP__
#define __BINARYSEARCHTREE_HPP__

#include <queue>
#include <stack>
#include <iostream>

using namespace std;

template <class T>
class Queue : public queue<T> {
public:
	T dequeue() {
		T retEl = queue<T>::front();
		queue<T>::pop();
		return retEl;
	}
	
	void enqueue(const T& el) {
		push(el);
	}
};

template <class T>
class Stack : public stack<T> {
public:
	T pop() {
		T retEl = stack<T>::top();
		stack<T>::pop();
		return retEl;
	}
};

template <class T>
class BSTNode {
public:
	BSTNode() : left(0), right(0) {}
	BSTNode(const T& el, BSTNode* l = 0, BSTNode* r = 0) : key(el), left(l), right(r) {}
	T key;
	BSTNode *left, *right;
};

template <class T>
class BST {
public:
	BST() : root(0) {}
	~BST() {
		clear();
	}
	void insert(const T& el);
	void clear() {
		clear(root);
		root = 0;
	}
	bool isEmpty() const {
		return root == 0;
	}
	void preorder() {
		preorder(root);
	}
	void inorder() {
		inorder(root);
	}
	void postorder() {
		postorder(root);
	}
	T* search(const T& v) const{
		return search (root, v);
	}
	
	void bredthFirst();
	
protected:
	BSTNode<T>* root;
	
	virtual void visit(BSTNode<T>* n) {
		cout << n->key << " ";
	}
	
	void clear(BSTNode<T>* n);
	T* search(BSTNode<T>* n, const T& v) const;
	void preorder(BSTNode<T>* n);
	void inorder(BSTNode<T>* n);
	void postorder(BSTNode<T>* n);
};

template <class T>
void BST<T>::insert(const T& el) {
	BSTNode<T> *cur = root, *prev = 0;
	if(root != 0) {
		while (cur != 0) {
			prev = cur;
			if(cur->key == el) {
				break;
			}
			else if (cur->key > el) {
				cur = cur->left;
				if(cur == 0){
					prev->left = new BSTNode<T>(el);
					break;
				}
			}
			else{ // (cur->key < el)
				cur = cur->right;
				if(cur == 0){
					prev->right = new BSTNode<T>(el);
					break;
				}
			}
		}
	}
	else {
		root = new BSTNode<T>(el);
	}
}

template <class T>
void BST<T>::bredthFirst() {
	Queue<BSTNode<T>*> nQueue;
	BSTNode<T>* cur = root;
	if(cur != 0) {
		nQueue.enqueue(cur);
		while(!nQueue.empty()) {
			cur = nQueue.dequeue();
			visit(cur);
			if(cur->left)
				nQueue.enqueue(cur->left);
			if(cur->right)
				nQueue.enqueue(cur->right);
		}
	}
}

template <class T>
void BST<T>::clear(BSTNode<T>* n) {
	if (n != 0) {
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

template <class T>
T* BST<T>::search(BSTNode<T>* n, const T& v) const{
	while(n != 0) {
		if(n->key == v)
			return &n->key;
		else if (n->key > v)
			n = n->left;
		else
			n = n->right;
	}
	return 0;
}

template <class T>
void BST<T>::preorder(BSTNode<T>* n) {
	if(n != 0) {
		visit(n);
		preorder(n->left);
		preorder(n->right);
	}
}

template <class T>
void BST<T>::inorder(BSTNode<T>* n) {
	if (n != 0) {
		inorder(n->left);
		visit(n);
		inorder(n->right);
	}
}

template <class T>
void BST<T>::postorder(BSTNode<T>* n) {
	if (n != 0) {
		postorder(n->left);
		postorder(n->right);
		visit(n);
	}
}

#endif // __BINARYSEARCHTREE_HPP__
