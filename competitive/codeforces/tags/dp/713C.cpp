#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	std::vector<ll> v1,v2;
	for(int i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		v1.push_back(k);
		v2.push_back(k);
		
	}
	sort(v2.begin(),v2.end());
	ll s1=0 ,s2=0, least = v2[0];

	for(int i=0;i<n;i++)
	{
		s1+=abs(v1[i]-(least+i));
		cout<<" diff 1  "<<v1[i]<<' '<<least+i<<endl;
	}

	least = v1[0];

	for(int i=0;i<n;i++)
	{
		s2+=abs(v1[i]-(least+i));
		cout<<" diff 2  "<<v1[i]<<' '<<least+i<<endl;

	}

	// for(int i=0;i<n;i++)
	// {
	// 	if(i>0)
	// 		if(v2[i-1]>=v2[i])
	// 			v2[i]=v2[i-1]+1;
	// 	s+=abs(v1[i]-v2[i]);
	// 	cout<<" diff bw  "<<v1[i]<<"  and "<<v2[i]<<endl;
	// }

	cout<<min(s1,s2)<<endl;
	return 0;
}