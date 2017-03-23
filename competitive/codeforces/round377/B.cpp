#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n,k,prev;
	cin>>n>>k;
	int a[n],s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0)
		{
			if(prev+a[i]<k)
			{
				s+=(k-(prev+a[i]));
				a[i]+=(k-(prev+a[i]));
			}
		}
		prev=a[i];
		// cout<<z<<' '
	}
	cout<<s<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}