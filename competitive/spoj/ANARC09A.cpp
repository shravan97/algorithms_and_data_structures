#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll count=1;
	while(1)
	{
		string s;
		cin>>s;
		// cerr<<" the string "<<s<<endl;

		if(s[0]=='-')
			break;
		if((s.size())&1)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			ll no=0,totc=0,toto=0;
			for(ll i=0;i<s.size();i++)
			{
				if(s[i]=='}')
					totc++;
				else
					toto++;
				if(totc>toto)
				{
					totc--;
					no++;
				}

			}
			if(toto>totc)
				cout<<count<<". "<<(no/2 + no%2)+(toto-totc)/2 + (toto-totc)%2<<endl;
			else
				cout<<count<<". "<<no/2 + no%2<<endl;

		}

		count++;
	}
	return 0;
}
