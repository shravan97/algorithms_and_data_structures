#include <iostream>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	ll a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	
	ll st=a[0]+b[0];
	for(int i=0;i<n;i++)
	{
		ll sa = a[i],sb=b[i];
		for(int j=i+1;i<n;i++)
		{
			sa|=a[i];
			sb|=b[i];
			if(st<sb+sa)
				st=sb+sa;
		}
	}

	cout<<st<<endl;
	return 0;
}