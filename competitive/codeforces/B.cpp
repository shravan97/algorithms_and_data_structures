#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n,k,req;
	cin>>n>>k;
	string s[n+1];
	std::map<int, int> lens;
	for(int i=0;i<=n;i++)
	{
		cin>>s[i];
		if(i!=n)
			lens[s[i].size()]++;
		else
			req=s[i].size();
	}

	std::map<int, int>::iterator it;
	int b=0,at=0;
	for(it=lens.begin();it!=lens.end();it++)
	{
		if(it->first!=req)
			b+=it->second;
		else
		{
			at=it->second;
			break;
		}
	}
	cout<<b+1+(b/k)*5<<' '<<b+at+((b+at-1)/k)*5<<endl;

	return 0;
}