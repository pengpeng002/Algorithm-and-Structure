void quick_Sort(int l, int r, int* a)//©Лее 
{
	if(l<r-1)
	{
		int temp=a[l];
		int i=l, j=r-1;
		while(i<j)
		{
			while(i<j && a[j]>=temp) j--;
			if(i<j) a[i]=a[j];
			while(i<j && a[i]<=temp) i++;
			if(i<j) a[j]=a[i]; 
		}
		a[i]=temp;
		quick_Sort(l, i, a);
		quick_Sort(i+1, r, a);
	}	
}
inline void Quick_Sort(int*arr, const int &maxn)
{
	quick_Sort(0, maxn, arr);
}
