#include <iostream>
#define max(a,b) (a>b ? a:b)
using namespace std;
typedef long long int ll;

int main()
{
	ll n , wmax ,i;
	cout<<"Enter the total number of items and maximum allowable weight : ";
	cin>>n>>wmax;

	ll weights[n] , values[n] , d[n+1][wmax+1];
	cout<<"enter weights :";

	for(i=0;i<n;i++)
		cin>>weights[i];

	cout<<"enter values :";

	for(i=0;i<n;i++)
		cin>>values[i];
	
	for(i=0;i<=n;i++)
	{
		for(ll j=0;j<=wmax;j++)
		{
			if(i==0||j==0)
				d[i][j]=0;
			else if(weights[i-1]<=j)
			{
				d[i][j]=max(d[i-1][j] , values[i-1]+d[i][j-weights[i-1]]);
			}
			else
				d[i][j]=d[i-1][j];
		}
	}

	cout<<"Total Value : "<<d[n][wmax];

	return 0;
}