void Shell_Sort(int* a, const int &maxn)//Ï£¶û 
{
	int val=maxn/2;
	while(val >= 1)
	{
		for(int i=val;i<maxn;i++)
		{
			int tar=a[i];
			int j=i-val;
			while(j>=0 && a[j] > tar)
			{
				a[j+val]=a[j];
				j-=val;
			}
			a[j+val]=tar;
		}
		val/=2;
	}
}
