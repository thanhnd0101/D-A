#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
#define min(a,b) (a<=b?a:b)

int mstatus = 4;
char Alphabet[] = { 'a', 'b' };


void computeTable(vector<vector<int>> &DFA, char Pattern[], char Alphabet[]);
bool compareSubString(string src, string sub);
bool DFA_Search(char Parttern[], char Text[]);

//Ham Tim kiem chuoi 
bool DFA_Search(char Parttern[], char Text[]){
	vector<vector<int>> DFA;
	DFA.resize(mstatus + 1);

	for (int i = 0; i <= mstatus; ++i){
		DFA[i].resize(strlen(Alphabet));
	}

	computeTable(DFA, Parttern, Alphabet);

	int q = 0;

	for (int i = 0; i < strlen(Text); ++i){
		q = DFA[q][Text[i] - 'a'];
		//if (q == -1)return false;
		if (q == strlen(Parttern)){
			cout << "vi tri thu " << i - strlen(Parttern) + 1 << endl;
		}
	}

	//if (q == 4) return true;
	//return false;
	return true;
}
//Ham so sanh đe kiem tra chuoi Hau To
bool compareSubString(string src, string sub){
	for (int i = 0; i < sub.size(); ++i){
		if (src[src.size() - sub.size() + i] != sub[i]){
			return false;
		}
	}
	return true;
}
// Ham tao ra bang DFA, co tinh chat bat dau bang aa, ket thuc bang bb.
void computeTable(vector<vector<int>> &DFA, char Pattern[], char Alphabet[]){
	char Pk[100], Pq[100], Pp[100];

	for (int q = 0; q <= mstatus; ++q){
		strncpy_s(Pq, Pattern, q);

		for (int i = 0; i < strlen(Alphabet); ++i){
			int k = min(mstatus + 1, q + 2);

			//Pp = Pq + Alphabet[i];
			strcpy_s(Pp, Pq);
			int len = strlen(Pp);
			Pp[len] = Alphabet[i];
			Pp[len + 1] = '\0';

			int p = q + 1;
			while (true){
				--k;

				//Pk = Pattern.substr(0, k);
				strncpy_s(Pk, Pattern, k);

				int j = 0;
				for (; k > 0 && Pk[k - 1 - j] == Pp[p - 1 - j] && j < k; ++j){}
				if (j == k) break;
			}

			DFA[q][i] = k;
		}
	}
}
int main(void){

	char Text[] = "aaaababbaabb";
	char Pattern[] = "aabb";

	/*if (DFA_Search(Pattern, Text)){
		cout << Text << "  yeah! We have: " << Pattern << endl;
		}
		else {
		cout << Text << "  Oh no! We do not have: " << Pattern << endl;
		}*/
	DFA_Search(Pattern, Text);
	return 0;
}