//Họ Tên:Nguyễn Duy Thanh
//MSSV: 1612628
//Bài tập 5: Cài đặt các thao tác trên danh sách liên kết
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x == info2.x)return 0;
	if (info1.x > info2.x)return 1;
	return -1;
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	l.pTail = l.pHead = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	return l.pHead == NULL;
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	Node* p = l.pHead;
	std::cout << str << std::endl;
	while (p){
		std::cout << p->info.x << "\t";
		if (CompareData(p->info, l.pTail->info))std::cout << "=>\t";
		p = p->pNext;
	}
	std::cout << std::endl;
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	Node* nNode = new Node;
	if (!nNode)return NULL;
	nNode->info = info;
	nNode->pNext = NULL;
	return nNode;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	Node* p = l.pHead;
	while (p){
		if (!CompareData(p->info, info)) return p;
		p = p->pNext;
	}
	return NULL;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	Node* p = l.pHead;
	while (p){
		if (index == 0)return p;
		index--;
		p = p->pNext;
	}
	return NULL;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	Node* p = l.pHead;
	int count = 0;
	while (p){
		if (!CompareData(p->info, pNode->info)) return count;
		p = p->pNext;
		count++;
	}
	return -1;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	Node* p = l.pHead;
	Node* prev = p;
	while (p){
		if (!CompareData(p->info, pNode->info))return prev;
		prev = p;
		p = p->pNext;
	}
	return NULL;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	if (!l.pHead){
		l.pHead = l.pTail = pNewNode;
	}
	else{
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	Node* pNewNode = CreateNode(info);
	if (!pNewNode)return NULL;

	AddHead(l, pNewNode);
	return pNewNode;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	if (!l.pHead){
		l.pHead = l.pTail = pNewNode;
	}
	else{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{
	Node* pNewNode = CreateNode(info);
	if (!pNewNode)return NULL;
	AddTail(l, pNewNode);
	return pNewNode;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	if (!l.pHead || !CompareData(q->info, l.pTail->info)){
		AddTail(l, pNewNode);
	}
	else{
		pNewNode->pNext = q->pNext;
		q->pNext = pNewNode;
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info)
{
	Node* pNewNode = CreateNode(info);
	if (!pNewNode)return NULL;

	AddAfter(l, q, pNewNode);
	return pNewNode;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	if (!l.pHead){
		AddHead(l, pNewNode);
	}
	else{
		Data x;
		x.x = -1;

		Node* h = CreateNode(x);
		h->pNext = l.pHead;

		Node *p1 = h;
		Node *p2 = h->pNext;

		while (p2 && CompareData(p2->info, q->info)){
			p1 = p2;
			p2 = p2->pNext;
		}
		delete h;

		AddAfter(l, p1, pNewNode);
	}
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	Node* pNewNode = CreateNode(info);
	if (!pNewNode)return NULL;

	AddBefore(l, q, pNewNode);
	return pNewNode;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	if (!l.pHead || CompareData(l.pHead->info, pNewNode->info) >= 0){
		AddHead(l, pNewNode);
	}
	else{
		Data x;
		x.x = -1;
		Node* h = CreateNode(x);
		h->pNext = l.pHead;

		Node *p1 = h;
		Node *p2 = h->pNext;

		while (p2 && CompareData(p2->info, pNewNode->info) == -1){
			p1 = p2;
			p2 = p2->pNext;
		}

		if (p2 == NULL){
			AddTail(l, pNewNode);
		}
		else{
			pNewNode->pNext = p2;
			p1->pNext = pNewNode;
		}
		delete h;
	}
}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (!pNewNode)return NULL;

	AddAscendingList(l, pNewNode);
	return pNewNode;
}

// 20. Hàm hủy một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveHead(List& l)
{
	if (!l.pHead) return NULL;
	if (!CompareData(l.pHead->info, l.pTail->info))return l.pHead;

	Node *p = l.pHead;
	l.pHead = l.pHead->pNext;
	return p;
}

// 21. Hàm hủy một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveTail(List& l)
{
	if (!l.pHead)return NULL;
	if (!CompareData(l.pHead->info, l.pTail->info))return l.pHead;

	Data x;
	x.x = -1;
	Node* h = CreateNode(x);
	h->pNext = l.pHead;

	Node *p1 = h;
	Node *p2 = h->pNext;

	while (p2 && CompareData(p2->info, l.pTail->info)){
		p1 = p2;
		p2 = p2->pNext;
	}
	delete h;

	l.pTail = p1;
	l.pTail->pNext = NULL;
	return p2;
}

// 22. Hàm hủy một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveAfter(List& l, Node* q)
{
	if (!l.pHead || !q || !CompareData(l.pHead->info, l.pTail->info) || !CompareData(q->info, l.pTail->info)){
		return NULL;
	}
	else{
		if (!CompareData(q->pNext->info, l.pTail->info)){
			l.pTail = q;
		}

		Node*p = q->pNext;
		q->pNext = p->pNext;
		return p;
	}
}

// 23. Hàm hủy một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveNode(List& l, Data info)
{
	Data x;
	x.x = -1;
	Node* h = CreateNode(x);
	h->pNext = l.pHead;

	Node *p1 = h;
	Node *p2 = h->pNext;

	while (p2 && CompareData(p2->info, info)){
		p1 = p2;
		p2 = p2->pNext;
	}

	if (p2 == NULL)return NULL;

	if (!CompareData(p2->info, l.pHead->info)){
		return RemoveHead(l);
	}
	else if (!CompareData(p2->info, l.pTail->info)){
		return RemoveTail(l);
	}

	Data tem = p1->info;
	*p1 = *p2;
	p1->info = tem;

	delete h;
	return p2;
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void RemoveAll(List& l)
{
	Node *p1 = l.pHead;
	Node *p2;

	while (p1){
		p2 = p1->pNext;
		delete p1;
		p1 = p2;
	}

	InitList(l);
}

//Sử dụng thuật toán Insertion Sort để sắp xếp DSLK
void InsertionSort(List& l){
	if (!l.pHead)return;

	List newList;
	InitList(newList);

	Node* current = l.pHead, *next = NULL;


	while (current){
		next = current->pNext;
		current->pNext = NULL;

		AddAscendingList(newList, current);

		current = next;
	}
	l = newList;
}

//Sử dụng thuật toán Selection Sort để sắp xếp DSLK
void SelectionSort(List& l){}

//Sử dụng thuật toán Quick Sort để sắp xếp DSLK
Node* FindRealTail(List l){
	Node* prep = NULL;
	Node* p = l.pHead;
	while (p){
		prep = p;
		p = p->pNext;
	}
	return prep;
}
void QuickSort(List& l){
	l.pHead = QuickRecursion(l);
	l.pTail = FindRealTail(l);
}
Node* QuickRecursion(List l){
	if (!l.pHead || l.pHead == l.pTail){
		return l.pHead;
	}
	List newl, temp;
	InitList(newl);

	Node* pivot = partition(l, newl);

	if (newl.pHead != pivot){

		temp = newl;
		Node* p = temp.pHead;
		while (p->pNext != pivot){
			p = p->pNext;
		}

		temp.pTail = p;
		temp.pTail->pNext = NULL;

		newl.pHead = QuickRecursion(temp);
		newl.pTail = FindRealTail(newl);

		newl.pTail->pNext = pivot;
	}

	temp.pHead = pivot->pNext;
	temp.pTail = FindRealTail(newl);

	pivot->pNext = QuickRecursion(temp);
	newl.pTail = FindRealTail(newl);

	return newl.pHead;
}
Node* partition(List& l, List& newl){
	Node*pivot = l.pTail;
	Node* precurr = NULL, *curr = l.pHead, *tail = pivot, *temp;

	while (curr != pivot){
		//Trường hợp current data < pivot data
		if (CompareData(curr->info, pivot->info) < 0){

			if (!newl.pHead){
				newl.pHead = curr;
			}

			precurr = curr;
			curr = curr->pNext;
		}
		else
		{
			//Trường hợp current data >= pivot data
			if (precurr){
				precurr->pNext = curr->pNext;
			}
			temp = curr->pNext;
			curr->pNext = NULL;
			tail->pNext = curr;
			tail = tail->pNext;

			curr = temp;
		}
	}

	if (!newl.pHead){
		newl.pHead = pivot;
	}
	newl.pTail = tail;

	return pivot;
}

//Sử dụng thuật toán Radix Sort để sắp xếp DSLK
int FindMaxValue(List l){
	Node* pmax = l.pHead;
	Node* p = l.pHead;
	while (p){
		if (CompareData(p->info, pmax->info) == 1){
			pmax = p;
		}
		p = p->pNext;
	}
	return pmax->info.x;
}
Node* LSD(List& l, int k){
	if (!l.pHead || l.pHead == l.pTail){
		return l.pHead;
	}

	//Khởi tạo danh sách tạm
	List temp[10];
	for (int i = 0; i < 10; ++i){
		InitList(temp[i]);
	}
	//Chuyển các nút vào theo thứ tự radix
	Node* after;
	Node* p = l.pHead;
	while (p){
		after = p->pNext;
		p->pNext = NULL;
		AddTail(temp[(p->info.x / k) % 10], p);
		p = after;
	}

	//Lấy nút xuất hiện đầu trong danh sách
	Node* head;
	for (int i = 0; i < 10; ++i){
		if (temp[i].pHead){
			head = temp[i].pHead;
			break;
		}
	}

	//Liên kết các nút lại với nhau
	for (int i = 0; i < 10; ++i){
		if (temp[i].pHead){
			for (int j = i + 1; j < 10; ++j){
				if (temp[j].pHead){
					temp[i].pTail->pNext = temp[j].pHead;
					break;
				}
			}
		}
	}

	return head;
}
void RadixSort(List& l){
	int	maxvalue = FindMaxValue(l);
	for (int i = 1; maxvalue / i > 10; i *= 10){
		l.pHead = LSD(l, i);
		l.pTail = FindRealTail(l);
	}
}