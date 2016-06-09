#include <stdio.h>
int main()
{
	int n ,a,i,crim=0,crim_prev=0;
	scanf("%d%d",&n,&a);
	int c[n];

	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	int l=a-1,r=a-1,count=1,l_limit=0,r_limit=0;
	// if(a==1 || a==0)
	// 	l=0;
	// else 
	// 	l=a-2;
	// if(a==n)
	// 	r=n-1;
	// else r=a;
	
	// if(n==2)
	// {
	// 	crim=c[0]+c[1];
	// }

	crim=c[a-1];
	if(l==0)
	{
		l_limit=2;
	}
	if(r==n-1)
		r_limit=2;


	while(!l_limit || !r_limit)
	{
		if(l>0)
		{
			if(--l ==0 && !r_limit)
				l_limit=2;
			else if(l==0)
				l_limit=1;
		}

		if(r<n-1)
		{
			if(++r == n-1 && !l_limit)
				r_limit=2;
			else if(r==n-1)
				r_limit=1;
		}

		if(l==a-count-1 && r==a-1+count)
		{
			crim+=((c[l]==1)&&(c[r]==1))?2:0;
		}
		else if(l_limit > r_limit)
		{
			crim+=c[r];
		}
		else if(r_limit > l_limit)
			crim+=c[l];

		count++;

	}
printf("%d\n", crim );
	
	return 0;
}