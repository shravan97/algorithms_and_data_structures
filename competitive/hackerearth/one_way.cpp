#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long int l;
struct point
{
	l x,y,val;
};

int main()
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		l n,i=0;
		scanf("%lld",&n);
		point a[n];
		while(i<n)
		{
			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].val);
			i++;
		}
		int possible=1;
		for(i=0;i<n-1;i++)
		{
			if((llabs(a[i].val - a[i+1].val))%2==0)
			{
				if((llabs(llabs(a[i].x - a[i+1].x) - llabs(a[i].y - a[i+1].y)))%2!=0)
				{
					possible=0;
					break;
				}
			}
			else
			{
				if((llabs(llabs(a[i].x - a[i+1].x) - llabs(a[i].y - a[i+1].y)))%2==0)
				{
					possible=0;
					break;
				}
			}
		}
		if(!possible)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}