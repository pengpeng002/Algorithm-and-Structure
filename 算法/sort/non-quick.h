void non_recursive_quick_sort(int* a, const int maxn)//·ÇµÝ¹é¿ìÅÅ 
{
	stack<int> sta;
	sta.push(0);
	sta.push(maxn);
	int r=maxn, l=0;
	while(!sta.empty())
	{
		int r=sta.top();sta.pop();
		int l=sta.top();sta.pop();
		if(l>=r-1) continue;
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
		sta.push(i+1);
		sta.push(r);
		
		sta.push(l);
		sta.push(i);
	}
}
