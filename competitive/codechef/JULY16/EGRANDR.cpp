#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		long long int n , sum=0 , temp;
		scanf("%lld",&n);
		bool full=0,fail=0;
		temp = n;
		while(temp--)
		{
			int gr;
			scanf("%d",&gr);
			if(gr==2)
				fail=1;
			else if(gr==5)
				full=1;
			sum+=gr;
		}

		if(fail)
			printf("No\n");
		else if((sum/n)<4)
			printf("No\n");
		else if(!full) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}