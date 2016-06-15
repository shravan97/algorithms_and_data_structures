#include <stdio.h>
int main()
{
	long long int n;
	int flag=0,i,j;
	scanf("%lld",&n);
	for(i=0;i<=n/1234567;i++)
	{
		for(j=0;j<=((n - (i*1234567))/123456);j++)
			if((n-(i*1234567)-(j*123456))%1234==0)
			{
				flag=1;
				break;
			}
	}
	
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}