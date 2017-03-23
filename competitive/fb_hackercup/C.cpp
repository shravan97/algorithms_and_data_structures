#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;

	cin>>t;

	while(t--)
	{

		ll h,s,mn=0,mx=0;
		cin>>h>>s;

		while(s--)
		{
			string s1;
			cin>>s1;
			ll t=0,d=0,pos=0,ex=0;
			int ad=0;

			while(s1[pos]!='d')
			{
				t=t*10+(s[pos]-48);
				pos++;
			}

			while(pos<s1.size())
			{
				d=d*10+(s1[pos]-48);
				pos++;
				if(s1[pos]=='+')
				{
					ad=1;
					break;
				}
				else if(s1[pos]=='-' )
				{
					ad=-1;
					break;
				}
			}

			if(pos!=s1.size())
			{
				pos++;
				while(pos<s1.size())
				{
					ex=ex*10+(s1[pos]-48);
					pos++;
				}
			}

			if(ad==1 || ad==0)
			{
				mn+=t+ex;
				mx+=(t*d) + ex;
			}
			else
			{
				mn+=(t-ex);
				mx+=(t*d)-ex;
			}

		}

		if(mn>h)
		{
			cout<<1.000000<<endl;
			continue;
		}
		else if(h>mx)
		{
			cout<<0.000000<<endl;
			continue;
		}
		else
		{
			cout<<(float)()
		}

	}
	return 0;
}