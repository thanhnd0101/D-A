#include <iostream>
#include <string.h>
#include <cmath>

void searchRabin_Krap(const char P[], const char T[], int prime){
	int N = strlen(T);
	int M = strlen(P);
	int hashP = 0, hashT = 0;

	for (int i = 0; i < M; ++i){
		hashP += (P[i] - 'a' + 1)*pow(prime, i);
		hashT += (T[i] - 'a' + 1)*pow(prime, i);
	}

	for (int i = 1; i <= N - M + 1; ++i){
		if (hashP == hashT){
			std::cout << i - 1 << std::endl;
		}
		hashT = (hashT - (T[i - 1] - 'a' + 1)) / prime + pow(prime, M - 1)*(T[i + M - 1] - 'a' + 1);
	}

}

void main(){
	searchRabin_Krap("abcdd", "aabcdddwd", 3);
}