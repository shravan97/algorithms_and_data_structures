#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class BearPasswordAny
{
public:
	string findPassword(std::vector<int> v)
	{
		ll sz = v.size()-1;
		string curr_str="";
		std::vector<ll> vals;
		for(;sz>0;sz--)
		{
			if(v[sz-1]<=v[sz])
				return "";
			string a="",b="";
			for(ll i=0;i<=sz;i++)
			{
				a+='a';
				b+='b';
			}

			cout<<" a at "<<sz<<" is  : "<<a<<endl;

			ll val=0,count=v.size();
			std::vector<ll>::iterator it;
			for(it=vals.begin();it!=vals.end();it++)
			{
				val+=(*it)*(count-(sz));
				cout<<val<<endl;
				count--;
			}

			cout<<" val is "<<val<<endl;

			bool c;
			if(!curr_str.empty() && curr_str[curr_str.size()-1]=='a')
				c=1;
			else if(!curr_str.empty())
				c=0;
			else
				c=0;
			ll num=0;

			for(ll i=v[sz]-val;i>0;i--)
			{
				curr_str+=(c==0)?a:b;
				num++;
				c=!c;
			}
			cout<<" pushing :  "<<num<<endl;
			vals.push_back(num);
		}

		return curr_str;
	}
};
int main(int argc, char const *argv[])
{
	BearPasswordAny b;
	int arr[5]={5,0,0,0,0};
	std::vector<int> v(arr,arr+5);
	cout<<b.findPassword(v)<<endl;
	return 0;
}