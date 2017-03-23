#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	string b[5][5];

	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			cin>>b[i][j];
		}
	int id;
	cin>>id;

	char myid ;
	myid=((char)(id+48));

	std::vector< pair<int,int> > empty,mine;

	int val=0,mx=0,my=0;


	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			string curr=b[i][j];
			if(curr[0]==myid)
			{
				mine.push_back(make_pair(i,j));
				int value = b[i][j][1]-48;
				if(value>val)
				{
					val = value;
					mx = j;
					my = i;
				}
			}
			else if(curr[0]=='0')
				empty.push_back(make_pair(i,j));
		}

	if( val==0)
	{
		for(auto pos:empty)
		{
			if(pos.first==0 && pos.second==0)
			{
				cout<<"0 0\n";
				return 0;
			}
			if(pos.first==0 && pos.second==4)
			{
				cout<<"0 4\n";
				return 0;
			}
			if(pos.first==4 && pos.second==0)
			{
				cout<<"4 0\n";
				return 0;
			}
			if(pos.first==4 && pos.second==4)
			{
				cout<<"4 4\n";
				return 0;
			}
		}	
			
		cout<<empty[0].first<<' '<<empty[0].second<<endl;
		return 0;
	}

	if(mine.size()==1)
	{
		if(!empty.empty())
		{
			cout<<empty[0].first<<' '<<empty[0].second<<endl;
		}
	}

	cout<<my<<' '<<mx<<endl;

	return 0;
}
