#include <cstdio>
int main(int argc, char const *argv[])
{
	int a1,a2;
	scanf("%d %d",&a1,&a2);
	long long int count=0;
	int s=a1+a2;
	if(a1==1 && a2==1)
	{
		printf("0\n");
		return 0;
	}
	while(a1>0 && a2>0)
	{
		if(a1==1)
		{
			a1+=1;
			a2-=2;
		}
		else if(a2==1)
		{
			a2=2;
			a1-=2;
		}
		else
		{
			if(a1 > a2)
			{
				a1-=2;
				a2+=1;
			}
			else
			{
				a2-=2;
				a1+=1;
			}
			
		}
		// printf(" h %d %d \n",a1,a2 );
		count++;
	}
	printf("%lld\n",count );
	return 0;
}