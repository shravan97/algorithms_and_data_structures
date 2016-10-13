#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;

	if(n&1)
	{
		if(n<3)
			cout<<-1<<endl;
		else
		{
			ll order = (n*n-1)/2;
			cout<<order<<' '<<order+1<<endl;
		}
	}
	else
	{
		if(n>2)
		{
			ll ord = n*n/4;
			cout<<ord-1<<' '<<ord+1<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}