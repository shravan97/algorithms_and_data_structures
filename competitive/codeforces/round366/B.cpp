#include <cstdio>
int main(int argc, char const *argv[])
{
	long long int i,n;
	scanf("%lld",&n);
	long long int t,no_times=0,no_2=0;

	for(i=0;i<n;i++)
	{
		scanf("%lld",&t);

		if(t&1)
		{
			no_times+=(t/2);
		}
		else no_times+=(t/2)-1;

		no_2+=(t/2);
		if(no_2&1)
		{
			if(no_times&1)
				printf("2\n");
			else printf("1\n");
		}
		else
		{
			if(no_times&1)
				printf("1\n");
			else printf("2\n");
		}
	}

	return 0;
}