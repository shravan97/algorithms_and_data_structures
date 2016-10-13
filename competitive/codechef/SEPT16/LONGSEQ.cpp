#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long int z=0,o=0;
		for(long int i=0;i<s.size();i++)
			if(s[i]=='0')
				z++;
			else o++;
		if(z==1||o==1)
			cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}