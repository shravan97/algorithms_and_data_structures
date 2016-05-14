#include <iostream>
#include <cstring>
typedef long long int ll;
using namespace std;

int main()
{
	int t,i;
	std::cin>>t;

	for(i=0;i<t;i++)
	{
		ll n , j;
		cin>>n;
		ll arr[n] , ranks[n];

		for(ll z=0;z<n;z++)
			cin>>arr[z];
		memset(ranks , 0 , sizeof(ranks));

		for(j=0;j<n;j++)
		{
			ranks[j]=j+1;

			for(ll k=j-1;k>=j-arr[j] && k>=0;k--)
			{
				if(k-arr[k] >= j-arr[j])
				{
					ranks[k]++;
					ranks[j]--;
				}
			}
		}

		for(j=0;j<n;j++)
			cout<<ranks[j]<<' ';

		cout<<'\n';
	}

	return 0;
}