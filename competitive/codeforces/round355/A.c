#include <stdio.h>
int main()
{
	int n,h;
	long int req=0;
	scanf("%d %d",&n,&h);
	int a[n];
	for(;n>0;n--)
	{
		scanf("%d",&a[n-1]);
		if(a[n-1]>h)
			req+=2;
		else
			req++;
	}
	printf("%ld\n",req );

	return 0;
}