#include <stdio.h>
#include <iostream>
#include <string.h>
int mark(char a, char text[])
{
	for (int i = 0; i < strlen(text); i++)
		if (text[i] == a) return i;
}
bool inText(char a, char text[], int mark)
{
	for (int i = 0; i <= mark; i++)
		if (a == text[i]) return true;
	return false;
}
int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
char* source(char text[])
{
	int count = 0;
	for (int i = 0; i <= strlen(text); i++)
		if (inText(text[i], text, i - 1) == false)
			count++;
	char* Source = new char[count + 1];
	for (int i = 0; i < count; i++)
		Source[i] = NULL;
	Source[count] = '\0';
	count = 0;
	for(int i = 0; i <= strlen(text); i++)
		if (inText(text[i], Source, count) == false)
		{
			Source[count] = text[i];
			count++;
		}
	return Source;
}
char* newText(char *text, int q, char a)
{
	char* New = new char(q + 2);
	for (int i = 0; i < q; i++)
		New[i] = text[i];
	New[q] = a;
	New[q + 1] = '\0';
	return New;
}
bool end(char word[], int k,  char text[])
{
	int textMark = strlen(text) - 1;
	for (int i = k - 1; i >= 0; i--)
	{
		if (word[i] != text[textMark]) return false;
		textMark--;
	}
	return true;
}
void computerTable(int** &dfa, char word[], char Source[])
{
	int k = 0;
	int m = strlen(word);
	for(int q = 0; q <= m; q++)
		for (int i = 0; i < strlen(Source); i++)
		{
			k = min(q+2,m+1);
			do
			{
				k--;
			} while (end(word, k, newText(word,q,Source[i])) == false);
			dfa[q][mark(Source[i],Source)] = k;
		}
}
void DFA(char word[], char text[])
{
	int m = strlen(word);
	int** dfa = new int*[strlen(word) + 1];
	for (int i = 0; i <= strlen(word); i++)
		dfa[i] = new int[strlen(source(text))];
	computerTable(dfa, word, source(text));
	int q = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		q = dfa[q][mark(text[i],source(text))];
		if (q == m) printf("Xuat hien tai vi tri %d\n", i - m + 1);
	}
	for (int i = 0; i <= strlen(word); i++)
		delete[] dfa[i];
	delete[] dfa;
}
void main()
{
	char word[50];
	char text[10000];
	printf("Nhap van ban: "); 
	gets_s(text);
	printf("Nhap chuoi muon tim: ");
	gets_s(word);
	DFA(word, text);
	system("pause");
}