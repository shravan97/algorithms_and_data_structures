#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int blues(string s,int st)
{
	int bl=0;
	for(int i=st;i<s.size();i++)
		if(s[i]=='B')
			bl++;

	return bl;
}
int blues_end(string s,int end)
{
	ll bl=0;
	for(int i=end;i>=0;i--)
		if(s[i]=='B')
			bl++;
	return bl;
}
int blues_bw(string s,int a,int b)
{
	int bl=0;
	for(int i=a;i<=b;i++)
		if(s[i]=='B')
			bl++;

	return bl;
}
int main(int argc, char const *argv[])
{
	int t,c=1;
	cin>>t;

	ofstream ofile;
	ofile.open("out.txt");

	while(t--)
	{
		string s;
		cin>>s;
		ll len = s.size(),a,b;
		cin>>a>>b;

		if((b-a+1)<=len)
		{
			// cout<<blues(s,(a%len==0)?len-1:a%len-1)<<endl;
			int bg=(a%len==0)?len-1:a%len-1;
			ofile<<"Case #"<<c<<": "<<blues_bw(s,bg,bg+b-a)<<endl;
			c++;
			continue;
		}

		int bg=((a)%(len)==0)?len:(a%len),e=(b-(a+len-bg))%len;
		e=(e==0)?len:e;
		int tot=blues(s,0);
		ll num=(b-(e)-(a+len-bg))/len;
		num = (num<0)?0:num;
		// cout<<" bg : "<<bg<<endl;
		// cout<<" e : "<<e<<endl;
		
		// cout<<" num : "<<num<<endl;
		ll sum = num*tot;
		// cout<<" sum : "<<sum<<endl;
		
		// cout<<" blues : "<<blues(s,bg-1)<<endl;
		// cout<<" blues_end : "<<blues_end(s,e-1)<<endl;
		
		sum+=(blues(s,bg-1) + blues_end(s,e-1));

		cout<<sum<<endl;
		ofile<<"Case #"<<c<<": "<<sum<<endl;
		c++;


	}
	return 0;
}
/*

4 8

8 - 5 +1

*/
