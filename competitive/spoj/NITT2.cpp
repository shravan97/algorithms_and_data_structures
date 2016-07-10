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
		// std::ios::sync_with_stdio(false);
		string num;
		long long int i;
		// scanf("%50001s",num);
		cin>>num;
		bool div4=0 , div9=0 , div7=0 , div3=0 , div25=0;
		long long int sz = num.length() ;
		// printf("%d\n",num.length() );

		// if(sz<3 || num[(num.length())]=='1' || num[(num.length())]=='3' || num[(num.length())]=='7' 
		// 	|| num[(num.length())]=='9')
		// 	printf("No No %d \n",num[(num.length())]);
		// else
		// {
			int arr[6] = {-2,-3,-1,2,3,1},cur=0;
			long long int s9=0,s7=0;

			// printf("%lld\n",sz );
			if(num=="0")
			{
				printf("Yes Yes\n");
				continue;
			}
		if((sz<3) || num[sz-1]=='1' || num[sz-1]=='3' || num[sz-1]=='7' 
			|| num[sz-1]=='9')
			printf("No No\n");

		else
		{
			// printf("%lld\n",sz );
			if(((int)(num[sz-2]) - 48)&1)
			{
				if(num[sz-1]=='2' || num[sz-1]=='6')
					div4=1;
			}
			else
			{
				if(num[sz-1]=='0' || num[sz-1]=='4' || num[sz-1]=='8')
					div4=1;
			}

			for(i=0;i<sz;i++)
			{
				s9+=((long long int)(num[i]) - 48);
				if(cur==6)
					cur=0;
				s7+=arr[cur]*((long long int)(num[i]) - 48);
				cur++;
			}

			int k=((int)(num[sz-1]) - 48) + ((int)(num[sz-2]) - 48)*10;
			if(k==25 || k==50 || k==75 || k==0)
				div25=1;

			// printf("%lld %lld \n",s7,s9 );
			if(s7<0)s7 = -1*s7;
			if((s7%7)==0) div7=1;
			if(s9%9==0)
			{
				div9=1;
				div3=1;
			}
			else if(s9%3==0)
				div3=1;
			if((div4==1) && (div9==1) && (div7==1))
				printf("Yes ");
			else printf("No ");

			if(div3 && div25 && div7)
				printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}