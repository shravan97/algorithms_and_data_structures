#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n;
	scanf("%lld",&n);

	long long int a[n],i,curr=1;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);

	for(i=0;i<n;i++)
	{
		if(a[i]>=curr)
		{
			curr++;
		}
	}
	printf("%lld\n",curr );
	return 0;
}