#include "NumbersTest.h"
#include <vld.h>
//#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"

int main(){

	NumbersTest test;
	//test.generateArrayToFile(100000, "Numbers2.txt");
	test.getFromFile("Numbers.txt");

	List l;
	InitList(l);
	Data info;
	for (int i = 0; i < test.m_size; ++i){
		info.x = test.m_numbers[i];
		AddHead(l, info);
	}

	StartCounter();
	MergeSort(l.pHead);
	l.pTail = FindRealTail(l);

	std::cout << "\n" << "Thoi gian sort:" << GetCounter() << "\n";

	std::cout << std::endl;

	//PrintList(l, "Sort: ");
	/*if (!test.isSorted()){
		std::cout << "Sort khong thanh cong\n";
		}
		else{
		std::cout << "Sort thanh cong\n";
		}*/

	RemoveAll(l);
	return 0;
}