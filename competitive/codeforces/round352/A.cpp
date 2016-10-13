#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,i,num=1,pos=1;
	bool flag=0;
	cin>>n;
	// string s='';

	while(!flag)
	{
		int temp=num,len=log(num)/log(10),tmp_len=len;
		// cout<<num<<" h"<<'\n';

		while(temp>0)
		{
			int r=temp%10;
			if(n==pos+len)
			{
				cout<<r<<'\n';
				flag=1;
			}
			temp/=10;
			len--;
		}
		num++;
		pos+=tmp_len+1;
	}

	return 0;
}