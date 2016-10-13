#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll a[n],b[n],i;

	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
			b[i]=a[i];
		else
			b[i]=a[i]+a[i+1];
	}
	for(i=0;i<n;i++)
		cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}