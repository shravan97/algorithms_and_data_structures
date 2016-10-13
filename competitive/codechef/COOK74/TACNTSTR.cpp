#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	long long int p=1;
	for(long int i=0;i<s.size();i++)
	{
		p=(p*(90-s[i]+1))%mod;
	}

	cout<<p-1<<endl;
	return 0;
}	