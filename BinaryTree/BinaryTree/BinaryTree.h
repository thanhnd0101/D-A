


typedef struct node* ref;
struct node
{
	int key;
	ref left;
	ref right;
};

ref getNode(int key);

ref tree(int n);
//duyệt trước
void TRUOC(ref root);
void deleteTree(ref root);

//duyệt theo thứ tự trước
void preOrder(ref root);

//duyệt theo thứ tự sau
void postOrder(ref root);
//duyệt theo thứ tự giữa
void inOrder(ref root);
//duyệt tìm kiếm. tiêu chuẩn: nút gốc (con) bất kì > key con trái, <key con phải
ref TimKiem(ref root, int key);

void TimKiem2(ref root, int key);