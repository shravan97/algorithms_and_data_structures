#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int s=0;
		string s1;
		int n,i,ev=0,odd=0;
		cin>>n>>s1;
		for(i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			s+=k;
			if(k&1) odd++;
			else ev++;
		}
		if(n==1)
			if(ev)
				if(s1=="Dee")
					cout<<"Dee\n";
				else cout<<"Dum\n";
			else cout<<"Dum\n";
		else
			cout<<"Dum\n";
		// if(s1="Dee")
		// 	if(s&1)
		// 	{
		// 		if(ev==odd && ev==1)
		// 			printf("Dee\n");
		// 		else printf("Dum\n");
		// 	}
		// 	else printf("Dum\n");
		// else 
		// 	printf("Dum\n");
	}
	return 0;
}