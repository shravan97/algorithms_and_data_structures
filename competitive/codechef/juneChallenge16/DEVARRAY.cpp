#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main()
{
	ll n , q ,i;
	scanf("%lld %lld" , &n,&q);
	ll a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	sort(a,a+n);

	for(i=0;i<q;i++)
	{

		ll val , j;
		scanf("%lld",&val);

		if(val>=a[0] && val<=a[n-1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}