#include "RedBlack_Tree.h"

ref getNode(int key, int color, ref nil){
	Node *p = new Node;
	p->key = key;
	p->color = color;
	p->left = p->right = p->parent = nil;
	return p;
}
void leftRotate(ref &root, ref nil, ref x){
	Node *y = x->right;

	x->right = y->left;
	if (y->left != nil)y->left->parent = x;
	y->parent = x->parent;

	if (x->parent == nil) root = y;
	else{
		if (x == x->parent->left){
			x->parent->left = y;
		}
		else{
			x->parent->right = y;
		}
	}
	y->left = x;
	x->parent = y;
}
void rightRotate(ref& root, ref nil, ref y){
	Node*x = y->left;

	y->left = x->right;
	if (x->right != nil)x->right->parent = y;
	x->parent = y->parent;

	if (y->parent == nil)root = x;
	else
	{
		if (y == y->parent->left){
			y->parent->left = x;
		}
		else{
			y->parent->right = x;
		}
	}
	x->right = y;
	y->parent = x;
}
void RBT_insertion(ref& root, ref nil, int key){
	Node* x = getNode(key, RED, nil);
	BST_insert(root, nil, x);
	Insertion_FixUp(root, nil, x);
}
void BST_insert(ref& root, ref nil, ref& x){
	Node *y = nil;
	Node *z = root;
	while (z != nil){
		y = z;
		if (x->key < z->key){
			z = z->left;
		}
		else z = z->right;
	}

	x->parent = y;
	if (y == nil){
		root = x;
	}
	else{
		if (x->key < y->key)y->left = x;
		else y->right = x;
	}
}
void Insertion_FixUp(ref& root, ref nil, ref& x){
	while (x->parent->color == RED){
		if (x->parent == x->parent->parent->left){
			ins_leftAdjust(root, nil, x);
		}
		else{
			ins_rightAdjust(root, nil, x);
		}
	}
	root->color = BLACK;
}
void ins_leftAdjust(ref& root, ref nil, ref& x){
	Node* u = x->parent->parent->right;

	if (u->color == RED){
		u->color = BLACK;
		x->parent->color = BLACK;

		x->parent->parent->color = RED;
		x = x->parent->parent;
	}
	else
	{
		if (x == x->parent->right){
			x = x->parent;
			leftRotate(root, nil, x);
		}
		x->parent->color = BLACK;
		x->parent->parent->color = RED;

		rightRotate(root, nil, x->parent->parent);
	}
}
void ins_rightAdjust(ref& root, ref nil, ref& x){
	Node *u = x->parent->parent->left;

	if (u->color == RED){
		x->parent->color = BLACK;
		u->color = BLACK;

		x = x->parent->parent;
		x->color = RED;
	}
	else
	{
		if (x == x->parent->left){
			x = x->parent;
			rightRotate(root, nil, x);
		}
		x->parent->color = BLACK;
		x->parent->parent->color = RED;

		leftRotate(root, nil, x->parent->parent);
	}
}