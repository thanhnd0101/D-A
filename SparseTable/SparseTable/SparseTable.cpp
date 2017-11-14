#include <iostream>
#include "SparseTable.h"

void InitSparseTable(SparseTable& table){
	table.col = 0;
	table.row = 0;
	table.row_col_List = NULL;
}
void InitHeader(HeaderRef head){
	head->colIndex = -1;
	head->rowIndex = -1;
	head->right = NULL;
	head->down = NULL;
}
HeaderRef findLastRow(SparseTable& table, int row){
	HeaderRef p = findDownHeader(table.row_col_List->down, row);
	if (!p)return NULL;
	while (p->right){
		p = p->right;
	}
	return p;
}
HeaderRef findLastDownHeader(SparseTable& table){
	HeaderRef p = table.row_col_List->down;
	if (!p)return NULL;
	while (p->down){
		p = p->down;
	}
	return p;
}
HeaderRef findRightHeader(HeaderRef table, int col){
	HeaderRef p = table;
	if (!p)return NULL;
	while (p && p->colIndex != col){
		p = p->right;
	}
	return p;
}
HeaderRef findDownHeader(HeaderRef table, int row){
	HeaderRef p = table;
	if (!p)return NULL;
	while (p && p->rowIndex != row){
		p = p->down;
	}
	return p;
}


HeaderRef getHeader(int rowIndex, int colIndex, int value){
	HeaderRef nHeader = new Header;
	nHeader->rowIndex = rowIndex;
	nHeader->colIndex = colIndex;
	nHeader->value = value;
	nHeader->right = NULL;
	nHeader->down = NULL;
	return nHeader;
}

void store(SparseTable& table){
	InitSparseTable(table);

	std::cout << "Nhap so dong: ";
	std::cin >> table.row;
	std::cout << "Nhap so cot: ";
	std::cin >> table.col;

	int temp = 0;
	table.row_col_List = new Header;
	InitHeader(table.row_col_List);
	//q chỉ đến danh sách cột
	//p chỉ đến danh sách dòng
	HeaderRef q, p, prevq, prevp;
	//prevp chỉ đến vị trí trước đó của p
	prevq = table.row_col_List;
	//prevq chỉ đến vị trí trước đó của q
	prevp = table.row_col_List;

	for (int i = 0; i < table.row; ++i){
		for (int j = 0; j < table.col; ++j){
			std::cout << "Nhap phan tu thu [" << i << "]" << "[" << j << "](khac 0): ";
			std::cin >> temp;
			//nếu tồn tại dữ liệu
			if (temp != 0){
				//Tìm thử xem vị trí danh sách cột và danh sách dòng đã có chưa
				p = findDownHeader(table.row_col_List->down, i);
				q = findRightHeader(table.row_col_List->right, j);
				//Nếu chưa có thì tạo mới vị trí danh sách cột,vị trí danh sách dòng
				if (!p){
					p = getHeader(i, -1, 0);
					prevp = table.row_col_List;
					//liên kết p với p trước đó
					while (prevp && prevp->down && prevp->down->rowIndex < i){
						prevp = prevp->down;
					}
					p->down = prevp->down;
					prevp->down = p;
				}
				if (!q){
					q = getHeader(-1, j, 0);
					prevq = table.row_col_List;
					while (prevq && prevq->right && prevq->right->colIndex < j){
						prevq = prevq->right;
					}
					//liên kết q với q trước đó
					q->right = prevq->right;
					prevq->right = q;
				}
				//Tạo ra 1 nút element mới
				HeaderRef k = getHeader(i, j, temp);
				//Tìm nút bên phải có colIndex bé hơn j
				while (p && p->colIndex < j){
					prevp = p;
					p = p->right;
				}
				//Gán bên phải của nút bên phải = nút element mới
				k->right = prevp->right;
				prevp->right = k;

				//Tìm nút bên dưới có rowIndex bé hơn i 
				while (q && q->rowIndex < i){
					prevq = q;
					q = q->down;
				}
				//Gán bên dưới của nút bên dưới  = nút element mới
				k->down = prevq->down;
				prevq->down = k;
			}
		}
	}

	//in ra man hinh
	for (int i = 0; i < table.row; ++i){
		for (int j = 0; j < table.col; ++j){
			p = findDownHeader(table.row_col_List->down, i);
			q = findRightHeader(table.row_col_List->right, j);
			if (p && q){
				q = findRightHeader(p, j);
				if (q){
					std::cout << q->value << "\t";
				}
				else{
					std::cout << "0 \t";
				}
			}
			else{
				std::cout << "0 \t";
			}
		}
		std::cout << std::endl;
	}
}
void deleteSparseTable(SparseTable& table){
	HeaderRef p = table.row_col_List->down;
	HeaderRef q, prep, preq;
	q = p->right;
	prep = p;
	while (p){
		q = p->right;
		preq = q;
		while (q){
			q = q->right;
			delete preq;
			preq = q;
		}

		p = p->down;
		delete prep;
		prep = p;
	}

	q = table.row_col_List->right;
	preq = q;
	while (q){
		q = q->right;
		delete preq;
		preq = q;
	}
	delete table.row_col_List;
}