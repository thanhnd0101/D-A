#include "RBTree.h"
#include <vld.h>
#include <iostream>


void main(){
	ref nil = new Node;
	nil->color = BLACK;
	nil->key = -1;
	nil->left = nil->right = nil->parent = nil;
	ref root = nil;


	RBT_insertion(root, nil, 40);
	RBT_insertion(root, nil, 90);
	RBT_insertion(root, nil, 20);
	RBT_insertion(root, nil, 5);
	RBT_insertion(root, nil, 100);
	RBT_insertion(root, nil, 200);

	RBT_Deletion(root, nil, 40);
	RBT_Deletion(root, nil, 90);
	RBT_Deletion(root, nil, 20);
	RBT_Deletion(root, nil, 5);
	RBT_Deletion(root, nil, 100);
	RBT_Deletion(root, nil, 200);
	delete nil;
}