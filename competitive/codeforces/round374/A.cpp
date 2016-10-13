#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	std::vector<int> v;
	std::vector<int>::iterator it;
	int val=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='B' && i!=0 && val!=0)
		{
			v.push_back(val);
			val=0;
		}
		else if(s[i]=='B') val++;
	}
	if(val!=0)
		v.push_back(val);

	cout<<v.size()<<endl;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<' ';
	cout<<endl;
	return 0;
}