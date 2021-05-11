void Selection_Sort(int* a, const int &maxn)//Ñ¡Ôñ 
{
	for(int i=0;i<maxn;i++)
	{
		int mi=i;
		for(int j=i+1;j<maxn;j++)
		{
			if(a[j] < a[mi]) mi=j;
		}
		if(i != mi) a[i]^=a[mi]^=a[i]^=a[mi];
	}
}
