#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	int n,d,i;
	scanf("%d %d",&n,&d);

	bool arr[d];
	memset(arr,0,d);
	for(i=0;i<d;i++)
	{
		char s[n];
		int j;
		scanf("%s",s);
		for(j=0;j<strlen(s);j++)
			if(s[j]=='0')
			{
				arr[i]=1;
				break;
			}
	}

	int count=0,max=0;

	for(i=0;i<d;i++)
	{
		if(arr[i]==1)
		{
			count++;
			if(count>max)
				max=count;
		}
		else
			count=0;
	}
	printf("%d\n",max );
	return 0;
}