#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	ll h=0,v=0;
	map<char,ll> dir;
	for(ll i=0;i<s.size();i++)
	{
		dir[s[i]]++;
	}
	h=abs(dir['L']-dir['R']);
	v=abs(dir['D']-dir['U']);
	
	if((h+v)&1)
		cout<<-1<<endl;
	else 
		cout<<(h+v)/2<<endl;
	return 0;
}