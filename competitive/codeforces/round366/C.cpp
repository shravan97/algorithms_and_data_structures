#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n,q,i,no_unread=0;
	cin>>n>>q;
	for(i=0;i<q;i++)
	{
		long long int typ , app;
		cin>>typ>>app;
		if(typ==1)
			no_unread+=1;
		else if(typ==2)
			no_unread-=1;
		else if(typ==3)
		{
			if(app>no_unread)
				no_unread=0;
			else
				no_unread-=app;
		}
		cout<<no_unread<<'\n';
	}
	return 0;
}