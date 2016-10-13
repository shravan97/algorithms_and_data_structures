#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll i,a[n],s=0,un=0;
	bool eq=1;
	std::map<ll, bool> m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(!m[a[i]])
		{
			m[a[i]]++;
			un++;
		}
		s+=a[i];
	}
	if(un>3)
		cout<<"NO\n";
	else cout<<"YES\n";
	// if(!(s%n==0))
	// {
	// 	cout<<"NO\n";
	// 	return 0;
	// }
	// ll diff=0,avg=s/n;
	// bool flag=1;

	// for(i=0;i<n;i++)
	// {
	// 	if(a[i]!=avg)
	// 	{
	// 		if(diff!=0 && abs(a[i]-avg)!=diff)
	// 		{
	// 			flag=0;
	// 			break;
	// 		}
	// 		else
	// 		{
	// 			diff=abs(a[i]-avg);
	// 		}
	// 	}
	// }

	// if(!flag)
	// {
	// 	cout<<"NO\n";

	// }
	// else cout<<"YES\n";


	return 0;
}