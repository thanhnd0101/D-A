#include "AVL_Tree.h"
#include <iostream>

Node* getNode(int key){
	Node* newNode = new Node;
	newNode->key = key;
	newNode->height = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
int height(Node *N){
	if (N){
		return N->height;
	}
	return 0;
}
int max(int A, int B){
	return A > B ? A : B;
}
//trường hợp mất cân bằng left - left
Node* rightRotate(Node* P){
	Node* p1 = P->left;
	Node* p2 = p1->right;

	p1->right = P;
	P->left = p2;

	P->height = max(height(P->right), height(P->left)) + 1;
	p1->height = max(height(p1->left), height(p1->right)) + 1;

	return p1;
}
//trường hợp mất cân bằng right - right
Node* leftRotate(Node* P){
	Node* p1 = P->right;
	Node* p2 = p1->left;

	p1->left = P;
	P->right = p2;

	P->height = max(height(P->right), height(P->left)) + 1;
	p1->height = max(height(p1->left), height(p1->right)) + 1;

	return p1;
}
int getBalance(Node *N){
	if (N){
		return height(N->right) - height(N->left);
	}
	return 0;
}
Node* insert(Node* &head, int key){
	if (!head){
		return getNode(key);
	}

	else if (key < head->key){
		head->left = insert(head->left, key);
	}
	else if (key > head->key){
		head->right = insert(head->right, key);
	}
	else // trường hợp key = head->key ở thời điểm hiện tại
		return head;

	head->height = max(height(head->left), height(head->right)) + 1;

	//trường hợp mất cân bằng
	int balance = getBalance(head);

	//trường hợp left-left
	if (balance < -1 && key < head->left->key){
		return rightRotate(head);
	}
	//trường hợp right-right
	if (balance > 1 && key>head->right->key){
		return leftRotate(head);
	}
	//trường hợp left-right
	if (balance<-1 && key>head->left->key){
		head->left = leftRotate(head->left);
		return rightRotate(head);
	}
	//trường hợp right-left
	if (balance > 1 && key < head->right->key){
		head->right = rightRotate(head->right);
		return leftRotate(head);
	}

	return head;
}