#include <stdio.h>
int main()
{
	int n,flag=0;
	scanf("%d",&n);

	for(;n>0;n--)
	{
		char s[11];
		int r1 , r2;
		scanf("%s %d %d",s,&r1,&r2);
		if(r1>=2400 && r2>r1)
		{
			flag=1;
		}
	}
	if(flag)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}