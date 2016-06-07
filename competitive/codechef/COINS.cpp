#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long int ll;
using namespace std;

ll find(char inp[11])
{
	if(inp[0]=='\n')
		return 0;
	else
	{
		ll num=0;
		for(ll i =0;i<strlen(inp);i++)
			num=num*10+(int)(inp[i])-48;
		return num;
	}

}

int main()
{
	ll n;
	char inp[11]={' '};
	bool flag=1;

	while(flag)
	{
		scanf("%s",inp);
		if(find(inp)==0)
		{
			flag=0;
		}
		else
		{
			ll num = find(inp);
			printf("%lld \n",num);
			printf("%lld\n",((num) < ((num/2)+(num/3)+(num/4)) ? ((num/2)+(num/3)+(num/4)) : num));
		}
	}


	return 0;
}