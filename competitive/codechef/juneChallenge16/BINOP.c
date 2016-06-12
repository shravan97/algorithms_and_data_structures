#include <stdio.h>
#include <string.h>
typedef long long int l;
int main()
{
	l t;
	scanf("%lld",&t);

	for(;t>0;t--)
	{
		char a[1000001], b[1000001];
		l i , no_0_to_1=0 , no_1_to_0=0, no_0_to_1_done=0 , no_1_to_0_done=0 ,zero=0,one=0;
		scanf("%s",a);
		scanf("%s",b);

		for(i=0;i<strlen(a);i++)
		{
			if(b[i]!=a[i])
			{
				if(a[i]=='1')
					no_1_to_0++;
				else no_0_to_1++;
			}
			else
			{
				if(a[i]=='1')
					one++;
				else zero++;
			}

		}

		int flag=1;
		l count=0;
		// printf("%lld %lld %lld %lld\n",no_0_to_1,no_1_to_0,zero,one );

		for(i=0;i<strlen(a);i++)
		{
			if(a[i]!=b[i])
			{
				if(a[i]=='1')
				{
					if(no_1_to_0_done>0)
					{
						no_1_to_0_done--;
						// printf("I\n");
					}
					else
					{
						if(no_0_to_1>0)
						{
							no_0_to_1--;
							no_1_to_0--;
							no_0_to_1_done++;
							count++;
							zero++;
							one++;
							// printf("II\n");
						}
						else if(zero>0)
						{
							zero++;
							one--;
							count++;
							// printf("III\n");
						}
						else
						{
							flag=0;
							// printf("IV\n");
							break;
						}
					}
				}

				else
				{
					if(no_0_to_1_done>0)
					{
						no_0_to_1_done--;
						// printf("VI\n");
					}
					else
					{
						if(no_1_to_0>0)
						{
							no_0_to_1--;
							no_1_to_0--;
							no_1_to_0_done++;
							count++;
							zero++;
							one++;
							// printf("VII\n");
						}
						else if(one>0)
						{
							one++;
							zero--;
							count++;
							// printf("VIII\n");
						}
						else
						{
							flag=0;
							// printf("IX\n");
							break;
						}
					}
				}
			}
		}
		if(!flag)
			printf("Unlucky Chef\n");
		else
			printf("Lucky Chef\n%lld\n",count);
	}

	return 0;
}