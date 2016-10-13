#include <iostream>
#include <stack>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	while(1)
	{
		ll n;
		bool flag=1;
		cin>>n;
		if(!n)break;
		ll a[n],i,track=1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		stack <ll> side;
		i=0;
		while(i<n)
		{
			// cout<<a[i]<<'\n';
			if(a[i]!=track)
			{
				if(!side.empty() && side.top()==track)
				{
					// cout<<"1\n";
					side.pop();
					track++;
				}
				else if(!side.empty())
				{
					// cout<<"2\n";
					if(side.top()<a[i])
					{
						// cout<<"exception "<<side.top()<<" - "<<a[i]<<'\n';
						flag=0;
						break;
					}
					else side.push(a[i]);

					i++;
				}
				else
				{ 
					side.push(a[i]);
					i++;
				}
			}
			else
			{ 
				track++;
				i++;
			}
		}
		if(flag)cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';

	}
	return 0;
}