#include <cstdio>
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll i,n;
	scanf("%lld",&n);
	ll arr[n];

	ll max_this_time =1,max=1;

	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(i>0)
		{
			if(arr[i]>arr[i-1])
				max_this_time++;
			else
			{
				if(max_this_time>max)
					max=max_this_time;
				max_this_time=1;
			}
		}
	}
	if(max<max_this_time)
		max = max_this_time;
	printf("%lld\n",max );

	return 0;
}