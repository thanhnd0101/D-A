#include "AVLTree.h"
#include <vld.h>
#include <iostream>
using namespace std;

int main()
{
	Node *root = NULL;

	/* Constructing tree given in the above figure */
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);


	cout << "Preorder traversal of the constructed AVL 	tree is \n";
	outTree(root);

	root = deleteNode(root, 10);



	cout << "\nPreorder traversal after deletion of 10 \n";
	outTree(root);

	root = deleteNode(root, 2);
	root = deleteNode(root, 0);
	root = deleteNode(root, 5);
	root = deleteNode(root, 1);
	root = deleteNode(root, 6);
	root = deleteNode(root, -1);
	root = deleteNode(root, 9);
	root = deleteNode(root, 11);
	return 0;
}