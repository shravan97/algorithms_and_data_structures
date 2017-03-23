#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll maxSum=0;

	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		ll s=0;
		for(int j=a-1;j<b;j++)
			s+=arr[j];

		if(s>0)
			maxSum+=s;

	}

	cout<<maxSum<<endl;

	return 0;
}
