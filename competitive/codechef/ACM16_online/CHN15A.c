#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,s=0;
		scanf("%d %d",&n,&k);

		for(i=0;i<n;i++)
		{
			long long int tem;
			scanf("%lld",&tem);
			if(((long long int)(tem+k)%7) ==0) s++;
		}
		printf("%d\n",s );

	}
	return 0;
}