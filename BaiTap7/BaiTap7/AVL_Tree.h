struct Node
{
	int key;
	int height;
	Node* left;
	Node* right;
};

Node* getNode(int key);
int height(Node *N);
int max(int A, int B);
//trường hợp mất cân bằng left - left
Node* rightRotate(Node* P);
//trường hợp mất cân bằng right - right
Node* leftRotate(Node* P);
int getBalance(Node *N);
Node* insert(Node* &head, int key);