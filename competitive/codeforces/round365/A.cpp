#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,i,m=0,c=0;
	scanf("%d",&n);
	int a,b;

	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)m++;
		else if(b>a)c++;
	}

	if(m>c)printf("Mishka\n");
	else if(c>m)printf("Chris\n");
	else printf("Friendship is magic!^^\n");
	return 0;
}