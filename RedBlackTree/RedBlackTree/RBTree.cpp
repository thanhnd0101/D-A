#include "RBTree.h"

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

void RBT_Deletion(ref& root, ref nil, int k){
	Node* z = searchTree(root, nil, k);
	if (z == nil)return;

	Node* y = (z->left == nil || z->right == nil) ? z : TreeSuccessor(root, nil, z);

	Node* x = (y->left == nil) ? y->right : y->left;

	x->parent = y->parent;

	if (y->parent == nil){
		root = x;
	}
	else if (y == y->parent->left)
	{
		y->parent->left = x;
	}
	else{
		y->parent->right = x;
	}

	if (y != z){
		z->key = y->key;
	}
	if (y->color == BLACK){
		Deletion_FixUp(root, nil, x);
	}
	delete y;
}
ref searchTree(ref root, ref nil, int k){
	Node*p = root;
	while (p != nil){
		if (p->key == k)return p;
		else if (p->key > k){
			p = p->left;
		}
		else
			p = p->right;
	}
	return nil;
}
ref TreeSuccessor(ref root, ref nil, ref z){
	Node* p = z->left;
	while (p->right != nil){
		p = p->right;
	}
	return p;
}
void Deletion_FixUp(ref& root, ref nil, ref x){
	while ((x->color == BLACK) && x != root){
		if (x == x->parent->left){
			del_leftAdjust(root, nil, x);
		}
		else
		{
			del_rightAdjust(root, nil, x);
		}
	}
	x->color = BLACK;
}
void del_leftAdjust(ref& root, ref nil, ref& x){
	Node* w = x->parent->right;

	if (w->color == RED){
		w->color = BLACK;
		x->parent->color = RED;
		leftRotate(root, nil, x->parent);
		w = x->parent->right;
	}
	if (w->left->color == BLACK && w->right->color == BLACK){
		w->color = RED;
		x = x->parent;
	}
	else {
		if (w->right->color == BLACK){
			w->left->color = BLACK;
			w->color = RED;
			rightRotate(root, nil, w);
		}
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->right->color = BLACK;
		leftRotate(root, nil, x->parent);
		x = root;
	}
}
void del_rightAdjust(ref& root, ref nil, ref& x){
	Node* w = x->parent->left;

	if (w->color == RED){
		w->color = BLACK;
		x->parent->color = RED;
		rightRotate(root, nil, x->parent);
		w = x->parent->left;
	}
	if (w->left->color == BLACK && w->right->color == BLACK){
		w->color == RED;
		x = x->parent;
	}
	else{
		if (w->left->color == BLACK){
			w->right->color = BLACK;
			w->color = RED;
			leftRotate(root, nil, w);
		}
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->left->color = BLACK;
		rightRotate(root, nil, x->parent);
		x = root;
	}
}