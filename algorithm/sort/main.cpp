#include <bits/stdc++.h>
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "selection.h"
#include "shell.h"
#include "sort.h"
#include "non-quick.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int maxn=5e3+5;
int a[maxn], b[maxn];
clock_t st, ed;
inline bool check()//��������㷨�Ƿ��д��� 
{
	for(int i=1;i<maxn;i++)
	{
		if(a[i] < a[i-1]) return true;
	}
	return false;
}
inline void print()//��ӡ���� 
{
	for(int i=0;i<maxn;i++) printf("%d%c", a[i], i==maxn-1?'\n':' ');
}
inline void cp()//����һ�� 
{
	for(int i=0;i<maxn;i++) a[i]=b[i];
}
inline void create()//����������� 
{
	srand(time(0));
	for(int i=0;i<maxn;i++) a[i]=b[i]=rand()%100;
}
int main(int argc, char** argv) {
	create();
	Shell_Sort(a, maxn);
	
	cp();st=clock();my_test_sort(a, a+maxn);ed=clock();
	printf("my test sort use time: %d\n", ed-st);
	
	cp();st=clock();sort(a, a+maxn);ed=clock();
	printf("stl sort use time: %d\n", ed-st);
	
	cp();st=clock();my_sort(a, a+maxn);ed=clock();
	printf("my sort use time: %d\n", ed-st);	
	
	cp();st=clock();Shell_Sort(a, maxn);ed=clock();
	printf("shell sort use time: %d\n", ed-st);
		
}
