#include <bits/stdc++.h>
using namespace std;
struct clck
{
	int h,m;

};

clck split(string s)
{
	int num=0;
	clck c;

	for(int i=0;i<s.size();i++)
	{
		if(s[i]==':')
		{
			c.h=num;
			num=0;
		}
		else num=num*10+((int)(s[i])-48);
	}
	c.m=num;
	return c;
}

int main(int argc, char const *argv[])
{
	bool ovr=0;

	while(!ovr)
	{
	string s;
	cin>>s;
	if(s=="0:00")
	{
		ovr=1;
		continue;
	}

	clck c1 = split(s);
	double ha=30.000*(double)(c1.h) , ma =6.000*(double)(c1.m) ;
	ha+=0.500*(double)(c1.m);
	cout<<((double)(abs(ha-ma)>180.000)?360.000-(double)abs(ha-ma):(double)abs(ha-ma))<<endl;
	
	}

	return 0;
}