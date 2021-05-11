void merge_Sort(int l, int r, const int maxn, int* a)//¹é²¢ 
{
	if(l<r-1)
	{
		int mid=(l+r)>>1;
		merge_Sort(l, mid, maxn, a);
		merge_Sort(mid, r, maxn, a);
		int i=l, j=mid, k=l;
		int *temp=new int[maxn];
		while(i<mid || j<r)
		{
			if(j>=r || (i<mid && a[i] < a[j])) temp[k++]=a[i++];
			else temp[k++]=a[j++];
		}
		for(int i=l;i<r;i++) a[i]=temp[i];
		delete []temp;
	}
}
inline void Merge_Sort(int*a, const int maxn)
{
	merge_Sort(0, maxn, maxn, a);
}
