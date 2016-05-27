#include <iostream>
using namespace std;
typedef long long int ll;
/*
f(val[i],sum) = f(val[i-1],sum-val[i])+val[i]
f[i][j]=f[i][j-a[i]]+a[i]

1 6 3 9 2 10

*/
int main()
{
	ll n , sum , i , j;
	cin>>n;

	ll a[n+1];
	a[0]=0;

	for(i=1;i<=n;i++)
		cin>>a[i];

	cin>>sum;

	ll val[n+1][sum+1];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			if(i==0 || j==0)
				val[i][j]=0;
			else if(j>=a[i])
			{
				ll temp =(val[i-1][j-a[i]]+a[i]);
				val[i][j]=(temp <=sum && temp>=val[i-1][j])?temp:val[i-1][j];
			}
			else
			{
				val[i][j]=val[i-1][j];
			}
		}
	}

	if(val[n][sum]==sum)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}