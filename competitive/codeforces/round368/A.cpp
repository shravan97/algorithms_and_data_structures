#include <cstdio>
#include <set>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	set <char> s;
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		char c1;
		for(j=0;j<m;j++)
		{
			cin>>c1;
			s.insert(c1);
		}
	}
	bool flag=0;
	if(s.size()>2)
	{
		cout<<"#Color"<<endl;
		return 0;
	}

	for(set <char>::iterator i=s.begin();i!=s.end();i++)
		if(*i != 'W' && *i!='B')
		{
			flag=1;
			break;
		}
	if(!flag)
		cout<<"#Black&White"<<endl;
	else cout<<"#Color"<<endl;
 
	return 0;  
}