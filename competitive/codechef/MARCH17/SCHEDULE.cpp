#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,k;

		cin>>n>>k;
		string s;
		cin>>s;

		if(s.size() ==2)
		{
			cout<<1<<endl;
			continue;
		}

		priority_queue <ll, std::vector<ll>, less<ll> > q;

		ll cur=1;
		if(s.size()>1)
			if(s[0]!=s[1])
				q.push(1);

		for(ll i=1;i<s.size();i++)
		{
			// cout<<" here "<<s[i]<<" , ";
			if(s[i] == s[i-1])
			{
				cur++;
				// cout<<cur<<endl;
			}
			else
			{
				q.push(cur);
				// cout<<" pushed "<<cur<<" , ";
				cur=1;
				// cout<<cur<<endl;
			}
		}

		q.push(cur);

		ll i;

		for( i=0;i<k;i++)
		{
			ll k1 = q.top();
			// cout<<k1<<endl;
			if(k1<=2)
				break;
			q.pop();
			if(k1&1)
			{
				q.push(k1/2);
				q.push(k1/2);
			}
			else
			{
				q.push(k1/2);
				q.push(k1/2-1);				
			}

			
		}


		if(q.top()==2 && i<k)
		{
			if(s[0]==s[1])
			{
				q.pop();
				q.push(1);
				i++;
			}
		}
		if(q.top()==2 && i<k)
		{
			if(s[s.size()-1]==s[s.size()-2])
			{
				q.pop();
				q.push(1);
				i++;
			}

		}
		

		cout<<q.top()<<endl;
	}
	return 0;
}