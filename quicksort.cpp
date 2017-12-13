#include <stdio.h>
#include <iostream>
#include <time.h>
#define MAX 10
struct Node
{
	int key;
	Node* next;
};
// Hàm Quick Sort
void quickSort(Node* &head)
{
	if (head == NULL) return;
	Node* sort[3];
	sort[0] = NULL;
	sort[1] = head;
	sort[2] = NULL;
	Node* p = head;
	Node* q = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		if (q->key < sort[1]->key)
		{
			q->next = sort[0];
			sort[0] = q;
		}
		if (q->key > sort[1]->key)
		{
			q->next = sort[2];
			sort[2] = q;
		}
	}
	quickSort(sort[0]);
	quickSort(sort[2]);
	Node* temp = sort[0];
	if (sort[0] != NULL)
	{
		while (temp->next != NULL) temp = temp->next;
		temp->next = sort[1];
		temp = sort[1];
		temp->next = sort[2];
		head = sort[0];
	}
	else
	{
		sort[1]->next = sort[2];
		head = sort[1];
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
	for(int i = 0; i < MAX - 1; i++)
		a[i].next = &a[i + 1];
	a[MAX - 1].next = NULL;
	Node* head = &a[0];
	printf("---Truoc sap xep---\n");
	print(head);
	quickSort(head);
	printf("---Sau sap xep---\n");
	print(head);
	system("pause");
}