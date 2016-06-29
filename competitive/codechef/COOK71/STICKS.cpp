#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);

		int l=0,b=0;
		bool flag=0;

		for(i=n-1;i>0;i--)
		{
			if(a[i]==a[i-1])
			{
				if(l==0)
					l=a[i];
				else 
				{
					b=a[i];
					flag=1;
					break;
				}
				i--;
			}
		}
		if(flag)
		{
			long long int area = l*b;
			printf("%lld\n",area);
		}
		else printf("-1\n");

	}
	return 0;
}