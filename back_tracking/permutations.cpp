#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

std::vector<string> p;
std::map<string, bool> chck;
/*  abcd
	abdc
	acbd
	acdb
*/

void permute(string s,ll l,ll r)
{
	if(l==r)
	{
		if(!chck[s])
		{
			p.push_back(s);
			chck[s]=1;
		}
	}


	for(ll i=l;i<r;i++)
	{
		swap(s[l],s[i]);
		// p.push_back(s);
		permute(s,l+1,r);
		
		
		swap(s[l],s[i]);
	}
}

int main(int argc, char const *argv[])
{
	permute("abcd",0,4);

	ll c=0;

	for(auto p1:p)
	{
		cout<<p1<<endl;
		c++;
	}
	cout<<c<<endl;
	return 0;
}
