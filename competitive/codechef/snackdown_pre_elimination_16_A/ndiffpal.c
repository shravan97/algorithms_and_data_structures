#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		char current='a';
		for(i=0;i<n;i++)
		{
			if(current=='z')
				current='a';
			printf("%c",current);
			current++;
		}

	printf("\n");
	}
	
	return 0;
}