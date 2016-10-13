#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l,b;
		scanf("%d",&n);
		scanf("%d %d",&l,&b);
		int max=(l>b)?l:b;
		int min=(l<b)?l:b;
		l = max;
		b=min;
		bool flag=0;
		n++;
		while(n--)
		{
			if(n==0)
			{
				flag=1;
				break;

			}
			else if(l!=b)
			{
				int new_l=(b>l-b)?b:l-b;
				int new_b=(b<l-b)?b:l-b;
				l = new_l;
				b = new_b;
				// printf("new l : %d , new b : %d\n",l,b );
			}
			else break;
		}
		if(flag)
			printf("Yes %lld\n",(long long int)(l*b) );
		else printf("No\n");
	}
	return 0;
}