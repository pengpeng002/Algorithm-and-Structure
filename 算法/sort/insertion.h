void Insertion_Sort(int* a, const int &maxn)//���� 
{
	for(int i=1;i<maxn;i++)
	{
		int tar=a[i];
		int j=i-1;
		while(j>0 && tar < a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j]=tar;
	}
}
