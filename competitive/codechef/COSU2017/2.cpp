#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		string s1,s2;

		cin>>s1>>s2;
		stack <char> st1,st2;

		for(ll i=s1.size()-1;i>=0;i--)
			st1.push(s1[i]);
		for(ll i=s2.size()-1;i>=0;i--)
			st2.push(s2[i]);

		string m="";

		while(!(st1.empty() && st2.empty()))
		{
			if(!st1.empty() && !st2.empty())
			{
				if(st1.top() <= st2.top())
				{
					m+=st1.top();
					st1.pop();
				}
				else
				{
					m+=st2.top();
					st2.pop();
				}
			}
			else if(!st1.empty())
			{
				m+=st1.top();
				st1.pop();
			}
			else if(!st2.empty())
			{
				m+=st2.top();
				st2.pop();
			}
		}

		cout<<m<<endl;

	}
	return 0;
}