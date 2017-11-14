#include "BinaryTree.h"
#include <vld.h>
#include <iostream>

void main(){
	ref root = tree(15);
	preOrder(root);
	ref p = getNode(-1);
	p->right = root;
	root = p;
	TimKiem2(root, 6);
	deleteTree(root);
}