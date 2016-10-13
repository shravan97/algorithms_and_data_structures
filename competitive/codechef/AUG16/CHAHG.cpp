#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		int n,i;
		cin>>n;
		set <int> inc , dec ;
		set <ll> ot;
		ll h[n] , m[n] ;
		int prev=-1;
		std::map< ll , std::vector<int> > times;

		for(i=0;i<n;i++)
		{
			cin>>h[i]>>m[i];
			if(i!=0)
			{
				ll time;
				if(h[i]>h[i-1])
				{
					cout<<" d ins "<<i-1<<'\n';
					if((i&1))
						dec.insert(i-1);
					else inc.insert(i-1);
					if(m[i]<m[i-1])
						times[abs(h[i]-h[i-1])/abs(m[i]-m[i-1])].push_back(i-1);
				}
				else if(h[i]<h[i-1])
				{
					cout<<" i ins "<<i-1<<'\n';
					inc.insert(i-1);
					if(m[i]>m[i-1])
						times[abs(h[i]-h[i-1])/abs(m[i]-m[i-1])].push_back(i-1);
				}
				else
				{
					cout<<" b ins "<<i-1<<'\n';
					inc.insert(i-1);
					dec.insert(i-1);
					if(m[i]!=m[i-1]) times[0].push_back(i-1);
				}
			}
		}

		std::map< ll , std::vector<int> >::iterator it;

		if(inc.empty() || dec.empty())
			ot.insert(0);

		cout<<"here \n ";


		for(it=times.begin();it!=times.end();it++)
		{
			cout<<" in here \n";
			std::vector<int>::iterator itr;
			bool is_equal=0;
			for ( itr = it->second.begin(); itr != it->second.end(); ++itr)
			{
				cout<<" inside \n";
				if(h[*itr]>h[(*itr) + 1])
				{
					inc.erase(inc.find(*itr));
					dec.insert(*itr);
				}
				else if(h[*itr]<h[(*itr) + 1])
				{
					cout<<" inside1 "<<*itr<<" "<<'\n';
					dec.erase(dec.find(*itr));
					inc.insert(*itr);
				}
				else
				{
					if(m[*itr] > m[(*itr) + 1])
					{
						dec.erase(inc.find(*itr));
					}
					else if(m[*itr] < m[(*itr) + 1])
						inc.erase(inc.find(*itr));
				}

				if(h[*itr]+m[*itr]*it->first == h[(*itr) + 1]+m[(*itr) + 1]*it->first) is_equal=1;
			}
			if(inc.empty()||dec.empty())
			{
				if(is_equal) ot.insert(it->first);
				else ot.insert(it->first);
			}
		}

		cout<<ot.size()<<'\n';
		set<ll>::iterator iter;
		for(iter = ot.begin();iter!=ot.end();iter++)
			cout<<*iter<<' ';
		cout<<'\n';
	}
	return 0;
}