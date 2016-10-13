#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int arr[t];

	for(int i=0;i<t;i++)
		cin>>arr[i];
	string s;
	bool flag=1;

	cin.ignore();
	for(int i=0;i<t;i++)
	{
		std::getline(std::cin,s);
		int n=0;
		for(int j=0;j<s.size();j++)
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')
				n++;
		if(n!=arr[i])
		{
			flag=0;
		}
	}
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}