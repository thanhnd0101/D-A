#include <iostream>
#include "BinaryTree.h"
#include <stack>

ref getNode(int key){
	ref nNode = new node;
	nNode->key = key;
	nNode->left = NULL;
	nNode->right;
	return nNode;
}

//Xây dựng cây nhị phân
ref tree(int n){
	if (n == 0) return NULL;
	int nl = n / 2;
	int nr = n - nl - 1;
	int k;
	std::cin >> k;
	ref p = getNode(k);
	p->left = tree(nl);
	p->right = tree(nr);
	return p;
}
void deleteTree(ref root){
	if (root){
		ref left = root->left;
		ref right = root->right;
		delete root;
		deleteTree(left);
		deleteTree(right);
	}
}
void TRUOC(ref root){
	if (root){
		std::cout << root->key << "\t";
		TRUOC(root->left);
		TRUOC(root->right);
	}
}
void preOrder(ref root){
	ref p = root;
	std::stack<ref> Stack;

	if (p){
		Stack.push(p);
		while (!Stack.empty()){
			p = Stack.top();
			Stack.pop();
			std::cout << p->key << "\t";
			if (p->right) Stack.push(p->right);
			if (p->left)Stack.push(p->left);
		}
	}
}
void postOrder(ref root){
	ref p, q;
	p = q = root;
	std::stack<ref> Stack;
	while (p){
		for (; p->left; p = p->left){ Stack.push(p); }

		while (p->right == NULL || p->right == q){
			std::cout << p->key << "\t";
			q = p;//q trỏ vào nút vừa xử lý
			if (Stack.empty()) return;
			p = Stack.top();
			Stack.pop();
		}
		Stack.push(p);
		p = p->right;
	}
}

void inOrder(ref root){
	ref p;
	p = root;
	std::stack<ref> Stack;

	while (p){
		while (p){
			if (p->right) Stack.push(p->right);
			Stack.push(p);
			p = p->left;
		}

		p = Stack.top();
		Stack.pop();

		while (!Stack.empty() && p->right == NULL){
			std::cout << p->key << "\t";
			p = Stack.top();
			Stack.pop();
		}
		std::cout << p->key << "\t";


		if (!Stack.empty()){
			p = Stack.top();
			Stack.pop();
		}
		else{
			p = NULL;
		}
	}
}

ref TimKiem(ref root, int key){
	ref p = root;
	while (p){
		if (p->key == key)return p;
		if (p->key < key) p = p->right;
		else p = p->left;
	}
	return p;
}
void TimKiem2(ref root, int key){
	ref q = root;
	ref p = q->right;
	int d = 1;
	while (p && d){
		if (p->key < key){
			q = p;
			p = p->right;
			d = 1;
		}
		if (p->key > key){
			q = p;
			p = p->left;
			d = -1;
		}
		else {
			d = 0;
		}
	}
	if (d == 0){
		std::cout << key << " thuoc trong tree";
	}
	else{
		p = getNode(key);
		if (d == 1){
			q->right = p;
		}
		else{
			q->left = p;
		}
	}
}