#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[n][n][n];

ll calc()
{
	
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	int c[n],i,b=0,count=0;
	ll p[n][m];
	for(i=0;i<n;i++)
	{
		bool flag=0;
		cin>>c[i];
		if(i!=0 && c[i]!=c[i-1]&&c[i-1]!=0)b++;
	}

	for(i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>p[i][j];
		}

	if(b==k)
	{
		cout<<0<<'\n';
		return 0;
	}
	else if(k<b)
	{
		cout<<-1<<endl;
		return	0;
	}

	return 0;
}