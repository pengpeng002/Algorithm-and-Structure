void Bubble_Sort(int* a, const int &maxn)//ц╟ещ 
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=i+1;j<maxn;j++)
		{
			if(a[i] > a[j]) a[i]^=a[j]^=a[i]^=a[j];
		}
	}
}
