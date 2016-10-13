#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,k,b;
		cin>>n>>k>>b;
		ll i;


		if(n>k*(k+1)/2 && k<1500000000)
		{
			cout<<-1<<endl;
			continue;
		}

		if(b>k)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(b==k)
		{
			if(n!=k*(k+1)/2)
			{
				cout<<-1<<endl;
				continue;
			}
			for(ll z=1;z<=k;z++)
			{
				if(z!=k)
					cout<<z<<' ';
				else cout<<z<<endl;
			}
			continue;
		}

		std::map<ll, bool> boxes;
		ll tb = b , tk=k,found=0,remain=n;

		for(i=k;i>=1;)
		{
			// cout<<" i "<<i<<endl;
			if(remain-i>=tb*(tb-1)/2)
			{
				boxes[i]=1;
				// cout<<" here "<<i<<endl;
				tb--;
				found++;
				remain = remain-i;
				i=(remain>i-1)?i-1:remain;
			}
			else i=(remain-tb*(tb-1)/2 <i )?remain-tb*(tb-1)/2:i-1;
			// cout<<" found so far : "<<found<<" tb "<<tb<<endl;

		}

		// cout<<found<<endl;

		if(found!=b)
		{
			cout<<-1<<endl;
			continue;
		}

		std::map<ll, bool>::iterator it;
		
		for(it=boxes.begin();it!=boxes.end();it++)
		{
			if(b!=1)
				cout<<it->first<<' ';
			else cout<<it->first<<endl;
			b--;
		}
	}
	return 0;
}