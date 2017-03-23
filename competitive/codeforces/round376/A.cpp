#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	char curr='a',z='z';
	int d=0;
	for(int i=0;i<s.size();i++)
	{
		// cout<<abs(123-(int)s[i])+abs(97-(int)curr)<<' '<<abs(97-(int)s[i])+abs(123-(int)curr)<<endl;
		int k=min(abs(curr-s[i]) , 26-abs(curr-s[i]));
		curr=s[i];
		d+=k;
	}
	cout<<d<<endl;
	return 0;
}