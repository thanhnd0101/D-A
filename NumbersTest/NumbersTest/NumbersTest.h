#ifndef _NUMBERSTEST_H
#define _NUMBERSTEST_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
#define SPACE " "

class NumbersTest
{
public:
	int *m_numbers;
	int m_size;
	NumbersTest();
	~NumbersTest();
	void getFromFile(const char* link);
	void generateArrayToFile(int size, const char* link);
	bool isSorted();

};




NumbersTest::NumbersTest(){
	m_numbers = NULL;
	m_size = 0;
}
NumbersTest::~NumbersTest(){
	delete[]m_numbers;
}
void NumbersTest::getFromFile(const char* link){
	std::ifstream file_in(link, std::istream::in);
	if (!file_in.is_open()){
		std::cout << "Khong the mo file";
		return;
	}
	file_in >> m_size;

	if (m_numbers) delete[]m_numbers;

	m_numbers = new int[m_size];
	for (int i = 0; i < m_size; ++i){
		file_in >> m_numbers[i];
	}
	file_in.close();
}
void NumbersTest::generateArrayToFile(int size, const char* link){
	m_size = size;
	m_numbers = new int[size];
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++){
		m_numbers[i] = (rand() % 10000000) + 1;
	}

	std::ofstream file_out(link);
	if (!file_out.is_open()){
		std::cout << "Khong the mo file";
		return;
	}
	file_out << m_size << SPACE;

	for (int i = 0; i < m_size; ++i){
		file_out << m_numbers[i] << SPACE;
	}
	file_out.close();
}
bool NumbersTest::isSorted(){
	for (int i = 0; i < m_size - 1; ++i){
		if (m_numbers[i] > m_numbers[i + 1]){
			return false;
		}
	}
	return true;
}
#endif // !_NUMBERSTEST_H



double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart);

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}


