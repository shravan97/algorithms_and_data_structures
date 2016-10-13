#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int f;
	cin>>f;
	string s;
	cin>>s;
	int h,h1,m;
	h = (int)s[0]-48;
	h1=(int)s[1]-48;
	m = (int)s[3]-48;

	if(f==24)
	{
		if(h>2)
			s[0]='0';
		else if(h==2)
			if(h1>3)
				s[1]='0';
	}
	else 
	{
		if(h>1||h==0)
			if(s[1]>'2')
				s[0]='0';
			else
				s[0]='1';
		else if(h==1)
			if(h1>2)
				s[1]='0';
	}

	if(m>5)
		s[3]='0';

	cout<<s<<endl;

	return 0;
}