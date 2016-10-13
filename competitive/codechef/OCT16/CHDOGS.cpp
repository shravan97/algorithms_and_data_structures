#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll s,v;
		cin>>s>>v;
		std::cout << std::fixed << std::showpoint;

		cout<<setprecision(6);
		cout<<((float)(2*s)/(float)(3*v))<<endl;
	}
	return 0;
}