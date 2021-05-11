#include <bits/stdc++.h>
using namespace std;
const int threshold=16;
inline bool cmp(int* a, int* b)
{
	return (*a) < (*b);
}
inline void swap(int* a, int* b)
{
	int c=*a;
	*a=*b;
	*b=c;
}
void mid_three(int* res, int* a, int* b, int* c)
{
	if(cmp(a,b))
	{
		if(cmp(b,c)) swap(res, b);
		else if(cmp(a,c)) swap(res, c);
		else swap(res, a);
	}
	else if(cmp(a,c)) swap(res, a);
	else if(cmp(b,c)) swap(res, c);
	else swap(res, b);
}
int* unguarded_partition(int* first, int* last, int* pivot)
{
	while(true)
	{
		while(cmp(first, pivot)) first++;
		last--;
		while(cmp(pivot, last)) last--;
		if(!(first < last)) return first;
		swap(first, last);
		first++;
	}
}
inline int* pivot(int* first, int* last)
{
	int* mid=first + (last-first) / 2;
	mid_three(first, first+1, mid, last-1);
	return unguarded_partition(first+1, last, first);
}
void intro_sort(int* first, int* last, int depth_limit)
{
	while(last-first > threshold)
	{
		if(depth_limit == 0)
		{
			__partial_sort(first, last, last, __gnu_cxx::__ops::__iter_less_iter());
			return ;
		}
		depth_limit--;
		int* mid=pivot(first, last);
		intro_sort(mid, last, depth_limit);
		last=mid;
	}
}
void intro_sort1(int* first, int* last, int depth_limit)
{
	if(last-first > threshold)
	{
		if(depth_limit == 0)
		{
			__partial_sort(first, last, last, __gnu_cxx::__ops::__iter_less_iter());
			return ;
		}
		depth_limit--;
		int* mid=pivot(first, last);
		intro_sort1(first, mid, depth_limit);
		intro_sort1(mid, last, depth_limit);
	}
}
void unguarded_linear_insert(int* last)
{
	int val=(*last);
	int* next=last-1;
	while(cmp(&val, next))
	{
		(*last) = (*next);
		last=next;
		next--;
	}
	(*last)=val;
}
void unguarded_insertion_sort(int* first, int* last)
{
	for(int* i=first; i!=last; i++)
	{
		unguarded_linear_insert(i);
	}
}
void insertion_sort(int* first, int* last)
{
	if(first == last) return ;
	for(int* i=first+1; i != last; i++)
	{
		if(cmp(i, first))
		{
			int val=(*i);
			_GLIBCXX_MOVE_BACKWARD3(first, i, i+1);
			*first=val;
		}
		else unguarded_linear_insert(i);
	}
}
void final_insertion_sort(int* first, int* last)
{
	if(last-first > threshold)
	{
		insertion_sort(first, last);
		unguarded_insertion_sort(first, last); 
	}
	else insertion_sort(first, last);
}
void my_sort(int* first, int* last)
{
	if(first != last)
	{
		intro_sort(first, last, log(last-first)*2);
		final_insertion_sort(first, last);
	}
}
void my_test_sort(int* first, int* last)
{
	if(first != last)
	{
		intro_sort1(first, last, log(last-first)*2);
		final_insertion_sort(first, last);
	}
}
