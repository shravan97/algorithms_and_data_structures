#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string replace(string s)
{
	string res="";
	for(int i=0;i<s.size();i++)
	{
		int sz=s.size();
		if(s[i]==' ')
		{
			res+="%20";
		}
		else
			res.push_back(s[i]);
	}

	return res;
}

int main(int argc, char const *argv[])
{
	cout<<replace("my home")<<endl;
	// string s="replace";
	// s.substr(2,4)="yooo";
	// cout<<s<<endl;
	return 0;
}
