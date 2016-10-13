#include <cstdio>
int main(int argc, char const *argv[])
{
	int a,b,c,d;
	bool flag=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a/b>0)
		if((float)((float)(a)/(float)(b)) == (float)((float)(c)/(float)(d)))
		{
			flag=1;
			printf("Possible\n");
		}
		else if(((float)((float)(a)/(float)(b)) == (float)((float)(d)/(float)(c))))
		{
			flag=1;
			printf("Possible\n");
		}

	else 
	{
		if(((float)((float)(b)/(float)(a)) == (float)((float)(d)/(float)(c))))
		{
			flag=1;
			printf("Possible\n");
		}
		else if(((float)((float)(b)/(float)(a)) == (float)((float)(c)/(float)(d))))
		{
			flag=1;
			printf("Possible\n");
		}


	}

	if(!flag)
	{
		if(a/c>0)
		{
			if(((float)((float)(a)/(float)(c)) == (float)((float)(b)/(float)(d))))
			{
				flag=1;
				printf("Possible\n");
			}
			else if(((float)((float)(a)/(float)(c)) == (float)((float)(d)/(float)(b))))
			{
				flag=1;
				printf("Possible\n");
			}
		}
		else
		{
			if(((float)((float)(c)/(float)(a)) == (float)((float)(b)/(float)(d))))
			{
				flag=1;
				printf("Possible\n");
			}
			else if(((float)((float)(c)/(float)(a)) == (float)((float)(d)/(float)(b))))
			{
				flag=1;
				printf("Possible\n");
			}
		}
	}

	if(!flag)
	{
		if(a/d>0)
		{
			if(((float)((float)(a)/(float)(d)) == (float)((float)(b)/(float)(c))))
			{
				flag=1;
				printf("Possible\n");
			}
			else if(((float)((float)(a)/(float)(d)) == (float)((float)(c)/(float)(b))))
			{
				flag=1;
				printf("Possible\n");
			}
		}
		else
		{
			if(((float)((float)(d)/(float)(a)) == (float)((float)(b)/(float)(c))))
			{
				flag=1;
				printf("Possible\n");
			}
			else if(((float)((float)(d)/(float)(a)) == (float)((float)(c)/(float)(b))))
			{
				flag=1;
				printf("Possible\n");
			}
		}
	}

	if(!flag)
		printf("Impossible\n");

	return 0;
}