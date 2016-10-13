#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		long long int m,f,st[n];
		scanf("%lld %lld",&m,&f);
		int ful=0,mul=0,tot=0;

		for(i=0;i<n;i++)
		{
			scanf("%lld",&st[i]);
			bool up=0;
			if(st[i]%m==0 && st[i]!=0)
			{
				mul++;
				tot++;
				up=1;
				
			}
			else if(st[i]%f==0 && st[i]!=0)
			{
				ful++;
				if(!up)
				{
					tot++;
				}
			}
		}
		// pcent = 0.7*(float)(n);
		if((tot)>=0.7*(float)(n))
		{
			printf("Yes\n");
			if(mul>ful)
				printf("Multan\n");
			else if(ful>mul)
				printf("Fultan\n");
			else printf("Both\n");
		}
		else printf("No\n");

	}
	return 0;
}