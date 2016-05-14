#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long int ll;
using namespace std;

int main()
{
	int t;
	std::cin>>t;

	for(;t>0;t--)
	{
		int n , j , plate_count=0;
		ll m;
		cin>>n>>m;
		ll arr[n];

		for(j=0;j<n;j++)
			cin>>arr[j];
		
		sort(arr,arr+n);

		for(j=n-1;j>=0;j--)
		{
			m-=arr[j];
			plate_count++;
			if(m<=0)
				break;
		}
		if(m<=0)
		{
			cout<<plate_count<<'\n';
		}
		else cout<<-1<<'\n';
	}

	return 0;
}