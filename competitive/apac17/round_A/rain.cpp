#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r , c,i,j;
		scanf("%d %d",&r,&c);
		int h[r][c];
		long long int diff=0;


		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				scanf("%d",&h[i][j]);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				int num=0;
				if(i>0 && h[i-1][j]<h[i][j])
					num++;
			}
		}
	}
	return 0;
}