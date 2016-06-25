#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,likes=0,colls=0;
		scanf("%d %d",&n,&m);
		char a[n][m];
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		
		for(i=0;i<m;i++)
		{
			likes=0;
			for(j=0;j<n;j++)
				if(a[j][i]=='1')likes++;
			colls += (likes*(likes-1))/2;
		}
		printf("%d\n",colls );
	}
	return 0;
}