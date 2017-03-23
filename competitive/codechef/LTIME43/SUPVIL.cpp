#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool chck(string s)
{
	ll len=s.size();
	if(len<3)
		return 0;
	if(len>=5)
	{
		if(s.substr(len-5,5)=="woman")
			return 1;
		else if(s.substr(len-3,3)=="man")
			return 1;
	}
	if(len>=3)
	{
		if(s.substr(len-3,3)=="man")
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;
		// cout<<"here \n";
		ll sp=0,v=0;
		bool flg=0;
		while(n--)
		{
			string k;
			cin>>k;

			if(flg)
				continue;

			if(chck(k))
				sp++;
			else
				v++;

			if(sp>=v+2)
			{
				cout<<"superheroes\n";
				flg=1;
			}
			else if(v>=sp+3)
			{
				cout<<"villains\n";
				flg=1;
			}
		}

		if(!flg)
			cout<<"draw\n";

	}
	return 0;
}