#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		std::vector< vector< pair<ll,bool> > > th(n);

		std::vector<ll> sz;
		ll tot=0;

		for (ll i = 0; i < n; ++i)
		{
			ll s;
			cin>>s;
			sz.push_back(s);
			ll j;
			tot+=s;
			// cout<<" set "<<i<<'\n';
			for(j=0;j<s;j++)
			{
				ll k;
				cin>>k;
				th[i].push_back(make_pair(k,0));
				// cout<<k<<' ';
			}
			// cout<<'\n';
		}

		ll ord[tot];

		std::vector< vector< pair<ll,bool> > >::iterator r;
		ll i=0,count=0;
		bool flag=0;
		for (int i = 0; i < tot; ++i)
		{
			bool flag1=0;
			cin>>ord[i];
			if(!flag)
			{
				for(r=th.begin();r!=th.end();r++)
				{
					// cout<<" here \n";
					for (std::vector< pair<ll,bool> >::reverse_iterator it1 = r->rbegin(); it1 != r->rend(); ++it1)
					{
						// cout<<" here also "<<it1->first<<" "<<it1->second<<'\n';
						if(*it1 == make_pair(ord[i],false))
						{
							// cout<<" marked "<<ord[i]<<'\n';
							*it1 = make_pair(ord[i],1);
							flag1=1;
						}
						else if(*it1 == make_pair(ord[i],true))
						{
							// cout<<" marked2 "<<ord[i]<<'\n';
							flag1=1;
							continue;
						}
						else if(it1->second==0) break;
						
					}
				}
				if(!flag1)flag=1;
			}
		}
		// for(r=th.rbegin();r!=th.rend();r++)
		// {
		// 	ll st=i;
		// 	for(;i<st+sz[n-count-1];i++)
		// 	{
		// 		// cout<<i<<' '<<st+sz[n-count-1]<<'\n';
		// 		if((*r)[ord[i]]==0)
		// 		{
		// 			flag=1;
		// 			break;
		// 		}
		// 		else (*r)[ord[i]]--;
		// 	}
		// 	if(flag)
		// 		break;
		// 	count++;
		// }

		if(flag)
			cout<<"No\n";
		else cout<<"Yes\n";

	}
	return 0;
}