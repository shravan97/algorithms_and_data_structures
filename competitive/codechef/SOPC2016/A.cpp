#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll getnum(string s)
{
	ll n=0;
	for(auto c:s)
		n=n*10+((int)(c-48));
	return n;
}
ll sum=0;

ll op=0;
void calc(int n,int pos,string cur,char prev)
{
	if(prev=='9')
		return;

	// cout<<cur<<endl;

	for(char i=prev+1;i<='9';i++)
	{
		cur[pos]=i;
		if(pos==n-1)
		{
			sum+=getnum(cur);
			// cout<<cur<<endl;
		}
		else
			calc(n,pos+1,cur,cur[pos]);
	}

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if(!n)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n>=7)
	{
		cout<<-1<<endl;
		return 0;
	}

	string num="";
	for(int i=0;i<n;i++)
		num+='0';

	calc(n,0,num,'0');
	cout<<sum<<endl;

	return 0;
}
