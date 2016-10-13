#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	bool l=0;
	while(n--)
	{
		if(l==0)
			printf("I hate ");
		else printf("I love ");
		l=!l;

		if(n==0) printf("it ");
		else printf("that ");
	}
	printf("\n");
	return 0;
}