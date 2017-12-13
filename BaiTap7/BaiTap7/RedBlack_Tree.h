#define BLACK 0
#define RED 1

typedef struct Node* ref;

struct Node
{
	int key;
	int color;
	ref parent;
	ref left;
	ref right;
};

ref getNode(int key, int color, ref nil);
void leftRotate(ref &root, ref nil, ref x);

void rightRotate(ref& root, ref nil, ref y);
void RBT_insertion(ref& root, ref nil, int key);
void BST_insert(ref& root, ref nil, ref& x);
void Insertion_FixUp(ref& root, ref nil, ref& x);
void ins_leftAdjust(ref& root, ref nil, ref& x);
void ins_rightAdjust(ref& root, ref nil, ref& x);