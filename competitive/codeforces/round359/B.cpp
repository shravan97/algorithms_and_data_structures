#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,i;
	scanf("%d",&n);
	long long int a[n],count=0;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				long long int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				printf("%d %d\n",j+1,j+2 );
				// count++;
			}
		}
	}
	// printf("%lld\n",count );
	// for(i=0;i<n;i++)
	// 	printf("%lld ",a[i] );
	return 0;
}