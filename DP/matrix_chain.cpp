#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
long long int matrix_chain(long long int *dim,long long int **least , long long int i, long long int j)
{
	if(i==j)return 0;

	if(*(*(least+i)+j)!=0)
		return *(*(least+i)+j);

	printf("Here\n");

	long long int min=INT_MAX;

	for(long long int z=i;z<j;z++)
	{
		printf("Here%lld\n",z);
		if(*(*(least+i)+z)==0)
			*(*(least+i)+z) = matrix_chain(dim , least , i ,z);
		if(*(*(least+z+1)+j)==0)
			*(*(least+z+1)+j) = matrix_chain(dim , least , z+1 ,j);
		
		*(*(least+i)+j) = *(*(least+i)+z) + *(*(least+z+1)+j) + (*(dim+i-1))*(*(dim+z))*(*(dim+j));
		if(min > *(*(least+i)+j))
			min = *(*(least+i)+j);
	}
	return min;
}

int main(int argc, char const *argv[])
{
	long long int n,i;
	scanf("%lld",&n);
	long long int dim[n+1];

	for(i=0;i<=n;i++)
		scanf("%lld",&dim[i]);

	long long int least[n+1][n+1];
	for(i=0;i<=n;i++)
		memset(least[i],0,n+1);

	long long int no_ops = matrix_chain(dim,(long long int **)least,1,n-1);
	printf("%lld\n",no_ops );

	return 0;
}