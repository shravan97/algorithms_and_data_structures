#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	for(;t>0;t--)
	{
		ll n , i;
		cin>>n;
		ll a[n] , b[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		ll no_students=0;
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			if(i==0)
			{
				if(a[0]>=b[0])
					no_students++;
			}
			else
			{
				if(b[i]<= abs(a[i] - a[i-1]))
					no_students++;
			}
		}

		cout<<no_students<<'\n';
	}

	return 0;
}