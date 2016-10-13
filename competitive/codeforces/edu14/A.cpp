#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,i,count=0;
	bool begin=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		if(b)count++;
	}
	if(count==n-1 && n>1)
		printf("YES\n");
	else if((n==1) && (count==1))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}