#include <bits/stdc++.h>
#define max(a,b)((a>b)?a:b)
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	while(1)
	{
		ll n1,n2;
		set<ll> s1,s2;
		cin>>n1;
		if(n1==0)break;

		for(ll i=0;i<n1;i++)
		{
			ll k;
			cin>>k;
			s1.insert(k);
		}

		cin>>n2;

		for(ll i=0;i<n2;i++)
		{
			ll k;
			cin>>k;
			s2.insert(k);
		}

		ll res=0;

		set<ll>::iterator it;
		// set<ll> s,sp;
		// if(n1>n2)
		// {
		// 	s=s2;
		// 	sp=s1;
		// 	it1=s1.begin();
		// }
		// else
		// {
		// 	s=s1;
		// 	sp=s2;
		// 	it1=s2.begin();
		// }

		std::vector<ll> intsn,sums1;
		ll sum=0,in=0;

		for(it=s1.begin();it!=s1.end();it++)
		{
			// ll sum=0;
			// cout<<"at 1  : "<<*it<<endl;
			if(s2.find(*it)!=s2.end())
			{
				intsn.push_back(*it);
				sums1.push_back(sum+*it);
				// cout<<" h sum1 : "<<sum+*it<<endl;
				sum=0;
				in++;
			}
			else
				sum+=*it;
		}
		ll pos=0,sc=0,esum=sum;
		sum=0;
		// bool done=0;
		for(it=s2.begin();it!=s2.end();it++)
		{
			if(pos<in && *it==intsn[pos])
			{
				// cout<<" h sum2 : "<<sum+*it<<endl;
				pos++;
				// if(pos==in)done=1;
				if(sums1[sc]>sum+*it)
					res+=sums1[sc];
				else
					res+=(sum+*it);
				sum=0;
				sc++;
			}
			else
				sum+=*it;
		}
		res+=max(esum,sum);
		cout<<res<<endl;

		// for(it=s.begin();it!=s.end();)
		// {
		// 	if(sp.find(*it)!=sp.end())
		// 	{
		// 		cout<<" choose "<<sum1<<' '<<sum2<<endl;
		// 		res+=max(sum1,sum2)+*it;
		// 		sum1=0;
		// 		sum2=0;
		// 	}
		// 	else
		// 	{
		// 		sum1+=*it;
		// 		cout<<" into s1 : "<<*it<<"  into s2 : "<<*it1<<endl;
		// 		sum2+=*it1;
		// 	}

		// 	*it1++;
		// }
		// ll sf=0;
		// set<ll>::iterator ite;
		// if(n1<n2)
		// 	ite=s2.end();
		// else ite=s1.end();

		// for(;it1!=ite;it1++)
		// 	sf+=*it1;
		// if(n1<n2)
		// {
		// 	cout<<res+max(sum1,sum2+sf)<<endl;
		// }
		// else
		// 	cout<<res+max(sum1+sf,sum2)<<endl;
	}
	return 0;
}