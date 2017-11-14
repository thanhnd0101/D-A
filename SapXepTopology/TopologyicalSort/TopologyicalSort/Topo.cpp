#include <vld.h>
#include <iostream>

typedef struct leader* lref;
typedef struct trailer* tref;
lref addList(lref& head, lref& tail, int value, int& count);
lref& topo();

struct leader
{
	//Mã nhận diện
	int key;
	//Số lượng phần tữ leader "đứng trước" phần tử leader đang xét
	int count;
	//Chỉ đến leader 
	lref next;
	//chỉ đến trailer
	tref trail;
};
struct trailer
{
	lref id;
	tref next;
};

void topo(lref& head, lref& tail){
	lref p, q;
	tref t;
	head = new leader;
	tail = head;

	int x, y, count = 0;
	//đọc vào key x, nếu x==0 hoặc y==0 thì dừng chương trình
	std::cin >> x;
	while (x){
		std::cin >> y;
		p = addList(head, tail, x, count);
		q = addList(head, tail, y, count);

		t = new trailer;
		t->id = q;
		t->next = p->trail;
		p->trail = t;
		q->count++;
		std::cin >> x;
	}

	// đưa nút count=0 ra trước
	p = head;
	head = NULL;
	while (p != tail){
		q = p;
		p = p->next;
		if (q->count == 0){
			q->next = head;
			head = q;
		}
	}

	//in danh sach
	lref racleader;
	tref ractrailer;
	q = head;

	while (q){
		std::cout << q->key << "==>";
		count--;
		t = q->trail;
		racleader = q;
		q = q->next;
		delete racleader;
		racleader = NULL;

		while (t){
			ractrailer = t;
			p = t->id;
			p->count--;
			if (p->count == 0){
				p->next = q;
				q = p;
			}
			t = t->next;
			delete ractrailer;
		}
	}
	delete tail;
	if (count == 0){
		std::cout << "Hurrrayyyy";
	}
}
lref addList(lref& head, lref& tail, int value, int& count){
	lref h = head;
	tail->key = value;
	while (h->key != value){ h = h->next; }
	if (h == tail){
		tail = new leader;
		tail->next = NULL;
		tail->trail = NULL;

		count++;
		h->count = 0;
		h->trail = NULL;
		h->next = tail;
	}

	return h;
}


void main(){
	lref head, tail;
	topo(head, tail);
	std::cout << std::endl;

}