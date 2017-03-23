#include <iostream>
#include <vector>
#include <map>

typedef long long int ll;
using namespace std;

std::vector<ll> vals,wt;
std::map<ll, ll> knap;

ll knapsack(ll w, ll max_wt, ll pos, ll max_pos)
{
	if(w<=0 || w>max_wt)
		return 0;
	
	// ll k=knapsack(w-1,max_wt,pos-1,max_pos);
	
	// ll k1=max(k,vals[pos]+knapsack(w-wt[pos],max_wt,max_pos));
	
	ll mx=0;
	for(ll i=pos;i<max_pos;i++)
	{
		ll k1=knapsack(w,max_wt,pos+1,max_pos);
		if(mx<k1)
	}	
	return knap[w];
}

int main(int argc, char const *argv[])
{
	ll totwt,n;
	cin>>totwt>>n;

	for(ll i=0;i<n;i++)
	{
		ll v,w;
		cin>>v>>w;
		vals.push_back(v);
		wt.push_back(w);
	}

	cout<<knapsack(1,totwt,n)<<endl;
	return 0;
}