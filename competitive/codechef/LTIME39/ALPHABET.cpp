#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	set <char> known;
	cin>>s;

	for (int i = 0; i < s.size(); ++i)
	{
		known.insert(s[i]);
	}

	int n;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		string w;
		cin>>w;
		bool flag=0;
		for(int j=0;j<w.size();j++)
			if(known.find(w[j])==known.end())
			{
				flag=1;
				break;
			}
		if(flag)
			cout<<"No\n";
		else cout<<"Yes\n";

	}

	return 0;
}