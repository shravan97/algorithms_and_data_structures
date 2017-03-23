#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n,k;

	cin>>n>>k;
	int num=0,t=0;
	for(int i=1;i<=n;i++)
	{

		t+=5*i;
		if(240-t<k)
		{
			cout<<i-1<<endl;
			return 0;
		}
		else if(240-t==k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	
	return 0;
}
