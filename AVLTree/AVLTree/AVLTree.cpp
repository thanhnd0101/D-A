#include "AVLTree.h"
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
Node* search(Node* head, int key){
	if (!head)return NULL;

	if (key == head->key)return head;
	else if (key < head->key){
		return search(head->left, key);
	}
	return search(head->right, key);
}
Node* maxRightNode(Node* head){
	Node* p = head;
	while (p->right){
		p = p->right;
	}
	return p;
}
Node* deleteNode(Node*& head, int key){
	if (!head)return head;

	else if (key < head->key){
		head->left = deleteNode(head->left, key);
	}
	else if (key > head->key){
		head->right = deleteNode(head->right, key);
	}
	else
	{
		//trường hợp chỉ có phần tử trái or phải or không có
		if (!head->left || !head->right){
			Node* temp = head->left ? head->left : head->right;

			//không có phần tử trái và phải
			if (!temp){
				temp = head;
				head = NULL;
			}
			else{//có phần tử trái or phải
				*head = *temp;
			}
			delete temp;
		}
		else
		{
			//tìm phan tử phải nhất bên trái
			Node* temp = maxRightNode(head->left);

			head->key = temp->key;
			//đến xóa phần tử phải nhất bên trái
			head->left = deleteNode(head->left, temp->key);
		}
	}

	//liệu head đã bị xóa
	if (!head)return head;

	//Cân bằng lại
	head->height = max(height(head->left), height(head->right));

	int balance = getBalance(head);

	//trường hợp left - left
	if (balance > 1 && getBalance(head->left) >= 0){
		return rightRotate(head);
	}
	//trường hợp left - right
	if (balance > 1 && getBalance(head->left) < 0){
		head->left = leftRotate(head->left);
		return rightRotate(head);
	}
	//trường hợp right - right
	if (balance < -1 && getBalance(head->right) <= 0){
		return leftRotate(head);
	}
	//trường hợp right-left
	if (balance < -1 && getBalance(head->right) > 0){
		head->right = rightRotate(head->right);
		return leftRotate(head);
	}

	return head;
}
void outTree(Node *head)
{
	if (head)
	{
		std::cout << head->key << " ";
		outTree(head->left);
		outTree(head->right);
	}
}
