#include <iostream>
#include <cstring>
#include <string>
using namespace std;

long long int a[5000];
string s;
long long find(int pos)
{
	if(pos >= s.length()-1 && s[pos]!='0')
		return 1;
	else if(pos >= s.length()-1 && s[pos]=='0')
		return 0;
	long long  k1=0,k2=0;

	if(s[pos]=='0' && s[pos+1]=='0')
		return 0;

	if(a[pos]!=0)
		return a[pos];
	else
	{
		if(s[pos]=='0')
			k1=0;
		else if(a[pos+1]!=0)
		{
			// cout<<"useful1! "<<pos<<' '<<s[pos];
			k1 = a[pos+1];
		}
		else
		{
			// cout<<"in here "<<pos<<' ';
			k1 = find(pos+1);
			a[pos+1] = k1;
		}
		
		if(((int)(s[pos]) - 48)*10 + ((int)(s[pos+1]) - 48) <=26 && s[pos]!='0')
		{
			if( ((pos+2) <= (s.length()-1)) && a[pos+2]!=0)
			{
				// cout<<"useful2! "<<pos<<' ';
				k2=a[pos+2];
			}
			else
			{
				// cout<<"here? "<<pos<<' ';
				k2 = find(pos+2);
				a[pos+2]=k2;
			}
		}
	}
	// cout<<k1<<' '<<k2<<' ';
	return k1+k2;
}

int main(int argc, char const *argv[])
{
	memset(a,0,5000);
	while(1)
	{
		cin>>s;
		if(s=="0")
			break;
		else cout<<find(0)<<'\n';
		// for(int j=0;j<s.length();j++)
			// cout<<a[j]<<'\n';
		memset(a,0,5000);

	}
	return 0;
}