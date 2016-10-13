#include <bits/stdc++.h>
#define min(a,b)((a<b)?a:b)
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,i,a;
	cin>>n>>a;

	ll r=0,l=0,mr=0,ml=0,le=0,lr=0;
	std::vector<ll> lv , rv;
	for(i=0;i<n;i++)
	{
		ll p;
		cin>>p;
		if(p<a)
		{
			le++;
			lv.push_back(a-p);
		}
		else
		{
			lr++;
			rv.push_back(p-a);
		}
		// if(p<a)
		// {
		// 	le++;
		// 	if(l<a-p)
		// 	{
		// 		if(le>1)
		// 			ml=l;

		// 		l=a-p;
		// 		if(le==1)
		// 			ml=l;

		// 		cout<<" ml "<<ml<<'\n';
		// 	}
		// 	else if(a-p>ml)
		// 		ml=a-p;
		// 	else if(le==2)
		// 		ml=a-p;
		// }
		// else
		// {
		// 	lr++;
		// 	if(r<p-a)
		// 	{
		// 		if(lr>1)
		// 			mr=r;
		// 		r=p-a;
		// 		if(lr==1)
		// 			mr=r;
		// 	}
		// 	else if(p-a>mr)
		// 		mr=p-a;
		// 	else if(lr==2)
		// 		ml=p-a;
		// }
	}
	sort(lv.begin(),lv.end());
	sort(rv.begin(),rv.end());
	if(le>1)
		ml=lv[le-2];

	if(lr>1) mr=rv[lr-2];

	// cout<<ml<<' '<<mr<<' '<<l<<' '<<r<<'\n';
	ll mml=0,mmr=0;
	if(le>0)
		mml = lv[le-1];
	if(lr>0) mmr = rv[lr-1];

	cout<<min(min(mml+2*mr , mmr+2*ml),min(ml+2*mmr,mr+2*mml))<<'\n';

	return 0;
}