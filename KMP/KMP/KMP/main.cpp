#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeArray(string Pattern, vector<int> &pi){
	pi[1] = 0;
	int k = 0;
	for (int q = 2; q <= Pattern.size(); ++q){
		while (k > 0 && Pattern[k] != Pattern[q - 1]){
			k = pi[k];
		}
		if (Pattern[k] == Pattern[q - 1])++k;
		pi[q] = k;
	}
}
void KMP(string Pattern, string Text){
	vector<int> pi(Pattern.size() + 1);
	computeArray(Pattern, pi);
	int q = 0;
	for (int i = 0; i < Text.size(); ++i){
		while (q > 0 && Pattern[q] != Text[i])
		{
			q = pi[q];
		}
		if (Pattern[q] == Text[i])++q;
		if (q == Pattern.size()){
			cout << i - Pattern.size() + 1 << endl;
			q = pi[q];
		}
	}
}

int main(void){

	string Text = "abcxabcdabxabcdabcdabcy";
	string Pattern = "abcdabcy";
	KMP(Pattern, Text);

	return 0;
}