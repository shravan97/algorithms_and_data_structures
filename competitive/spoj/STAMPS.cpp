#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int l;
int main(int argc, char const *argv[])
{
	l t,i;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		l r,n,j,s=0;
		scanf("%lld %lld",&r,&n);
		l a[n];

		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			s+=a[j];
		}
		if(r>s)
			printf("Scenario #%lld:\nimpossible\n",i+1 );
		else
		{
			l curr = n-1,count=0;
			s=0;
			sort(a,a+n);
			while(s<r)
			{
				s+=a[curr--];
				count++;
			}
			printf("Scenario #%lld:\n%lld\n",i+1,count);
		}
	}
	return 0;
}