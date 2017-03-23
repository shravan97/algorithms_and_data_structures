#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool chckUniq(string s)
{
	map <char,bool> chck;

	for(auto c:s)
		if(chck[c])
			return 0;
		else
			chck[c]=1;
	return 1;
}

bool chckUniq2(string s)
{
	if(s.empty())
		return 1;
	sort(s.begin(),s.end());

	char prev=s[0];
	for(ll i=1;i<s.size();i++)
		if(prev==s[i])
			return 0;
		else
			prev=s[i];

	return 1;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	cout<<chckUniq(s)<<endl;
	cout<<chckUniq2(s)<<endl;



	return 0;
}
