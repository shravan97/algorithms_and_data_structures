#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;

	if(s1.size()!=s2.size())
	{
		cout<<-1<<endl;
		return 0;
	}

	std::map<char, bool> done;
	std::map<char, char> subs;
	for(int i=0;i<s1.size();i++)
	{
		if(!done[s1[i]])
		{
			if(done[s2[i]])
			{
				cout<<-1<<endl;
				return 0;
			}
			done[s1[i]]=1;
			done[s2[i]]=1;
			subs[s1[i]]=s2[i];
			subs[s2[i]]=s1[i];
		}
		else if(!done[s2[i]])
		{
			if(done[s1[i]])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else if(done[s1[i]] && done[s2[i]])
		{
			if(subs[s1[i]]!=s2[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	std::map<char, bool> done1;
	std::vector< pair<char,char> > req;

	for(auto c:subs)
	{
		if(!done1[c.first] && !done1[c.second])
		{
			if(c.first!=c.second)
			{
				req.push_back(make_pair(c.first,c.second));
				done1[c.first]=1;
				done1[c.second]=1;
			}
		}
	}

	cout<<req.size()<<endl;

	for(auto p:req)
	{
		cout<<p.first<<' '<<p.second<<endl;
	}
	
	return 0;
}