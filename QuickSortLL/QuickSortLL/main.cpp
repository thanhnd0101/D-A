#include <stdio.h>
#include <iostream>
#include <time.h>

#define MAX 5
struct Node
{
	int key;
	Node* next;
};
// Hàm Quick Sort
//void quickSort(Node* &head)
//{
//	if (head == NULL) return;
//	Node* sort[3];
//	sort[0] = NULL;
//	sort[1] = head;
//	sort[2] = NULL;
//	Node* p = head;
//	Node* q = NULL;
//	while (p != NULL)
//	{
//		q = p;
//		p = p->next;
//		if (q->key < sort[1]->key)
//		{
//			q->next = sort[0];
//			sort[0] = q;
//		}
//		if (q->key > sort[1]->key)
//		{
//			q->next = sort[2];
//			sort[2] = q;
//		}
//	}
//	quickSort(sort[0]);
//	quickSort(sort[2]);
//	Node* temp = sort[0];
//	if (sort[0] != NULL)
//	{
//		while (temp->next != NULL) temp = temp->next;
//		temp->next = sort[1];
//		temp = sort[1];
//		temp->next = sort[2];
//		head = sort[0];
//	}
//	else
//	{
//		sort[1]->next = sort[2];
//		head = sort[1];
//	}
//}
Node* getNode(int k){
	Node*p = new Node;
	p->key = k;
	p->next = NULL;
	return p;
}
void quickSort(Node* &head)
{
	if (head == NULL) return;
	Node* pitvot = head;
	Node* head1 = NULL, *head2 = NULL;
	Node* q;
	Node*p = head->next;

	while (p)
	{
		q = p;
		p = p->next;
		if (q->key < pitvot->key){
			q->next = head1;
			head1 = q;
		}
		else
		{
			q->next = head2;
			head2 = q;
		}
	}
	quickSort(head1);
	quickSort(head2);
	p = head1;
	if (p)
	{
		while (p->next) p = p->next;
		p->next = pitvot;
		pitvot->next = head2;
		head = head1;
	}
}
void AddAdscending(Node* &head, Node* k){
	if (!head) {
		head = k;
		return;
	}
	Node* h = getNode(-1);
	h->next = head;
	Node *r = h;

	Node* p = head;
	while (p && p->key < k->key){
		h = p;
		p = p->next;
	}
	k->next = h->next;
	h->next = k;
	if (p == head){
		head = k;
	}
	delete r;
}
void insersort(Node* &head){
	Node *h = NULL;
	Node*p = head;
	Node*q;
	while (p){
		q = p;
		p = p->next;
		q->next = NULL;
		AddAdscending(h, q);
	}
	head = h;
}
int findmax(Node* head){
	if (!head) return -1;
	Node*p = head;
	int max = head->key;
	while (p->next){
		if (p->key > max)max = p->key;
		p = p->next;
	}
	return max;
}
void AddTail(Node* head, Node *k){
	if (!head){
		head = k;
		return;
	}
	Node* p = head;
	while (p->next)p = p->next;
	p->next = k;
}
void LSD(Node* &head, int k){
	if (!head)return;

	Node *tem[10];
	for (int i = 0; i < 10; ++i){
		tem[i] = getNode(-1);
	}

	Node* p = head;
	Node*q;
	while (p){
		q = p->next;
		p->next = NULL;
		AddTail(tem[(p->key / k) % 10], p);
		p = q;
	}

	for (int i = 0; i < 9; ++i){
		if (tem[i]->next){
			for (int j = i + 1; j < 10; ++j){
				if (tem[j]->next){
					p = tem[i]->next;
					while (p->next)p = p->next;
					p->next = tem[j]->next;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 10; ++i){
		if (tem[i]) {
			head = tem[i]->next;
			break;
		}
	}
	for (int i = 0; i < 10; ++i){
		delete tem[i];
	}
}
void radixsort(Node* &head){
	int max = findmax(head);
	for (int i = 1; max / i>0; i *= 10){
		LSD(head, i);
	}
}
void print(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		printf("%d ", p->key);
		p = p->next;
	}
	printf("\n");
}

void main()
{
	Node a[MAX];
	for (int i = 0; i < MAX; i++)
		a[i].key = rand() % (10 * MAX);
	for (int i = 0; i < MAX - 1; i++)
		a[i].next = &a[i + 1];

	a[MAX - 1].next = NULL;
	Node* head = &a[0];
	printf("---Truoc sap xep---\n");
	print(head);
	radixsort(head);
	printf("---Sau sap xep---\n");
	print(head);

}