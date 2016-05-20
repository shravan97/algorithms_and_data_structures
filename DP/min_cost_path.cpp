#include <iostream>
using namespace std;
typedef long long int ll;

ll min(ll a,ll b,ll c)
{
	if(a>b)
	{
		return (b>c)?c:b;
	}
	else
		return (a>c)?c:a;
}

int main()
{
	ll m , n ,i , j;
	cin>>m>>n;

	ll c[m][n] , l[m+1][n+1];

	for ( i = 0; i < m; ++i)
	{
		for(j=0;j<n;j++)
			cin>>c[i][j];
	}

	for(i=1;i<=m;i++)
	{
		l[i][0] = l[i-1][0]+c[i-1][0];
	}

	for(j=1;j<=n;j++)
	{
		l[0][j] = l[0][j-1]+c[0][j-1];
	}
	

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			l[i][j]=min(l[i-1][j],l[i][j-1],l[i-1][j-1])+c[i-1][j-1];
		}
	}

	cout<<"The total cost of the 'least cost path' is  : "<<l[m][n];

	return 0;
}