#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

std::vector<ll> returnSpans(std::vector<ll> stocks)
{
	stack< pair<ll,ll> > s;
	std::vector<ll> spans;
	cout<<" h1 \n";
	bool prev=0;
	for(ll i=0;i<stocks.size();i++)
	{

		ll curr=1;
		if(i>0 && stocks[i]>=stocks[i-1])
		{
			curr+=spans[i-1];
			if(prev)
				s.pop();

			ll prev_stock;
			prev_stock=i;
			while(!s.empty() && s.top().first<=stocks[i])
			{
				curr+=(prev_stock-s.top().second);
				prev_stock=s.top().second;
				s.pop();

			}
			spans.push_back(curr);
			prev=0;
		}
		else
		{
			spans.push_back(1);
			s.push(make_pair(stocks[i],i));
			prev=1;
		}
	}

	cout<<" h2 \n";

	return spans;
}

int main(int argc, char const *argv[])
{
	ll st[7]={100, 80, 60, 70, 60, 75, 85};
	std::vector<ll> stocks(st, st+7);
	cout<<" here \n";

	std::vector<ll> spans=returnSpans(stocks);
	for(auto span:spans)
	{
		cout<<span<<' ';
	}
	cout<<endl;
	return 0;
}
