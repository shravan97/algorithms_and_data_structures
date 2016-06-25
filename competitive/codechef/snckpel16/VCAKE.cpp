#include <cstdio>
using namespace std;
typedef long long int l;
bool chck(l m , l k , l j , l b , l s , l area)
{
	int flag=0;
	if(m%b==0 && (m/b)<s)
			{
				flag=1;
				area-=m;
				s-=(m/b);
				// printf("Here1  %lld %lld %lld\n",area , s,b);
			}
			else if(m%s==0 && (m/s)<b)
			{
				flag=1;
				area-=m;
				b-=(m/s);
			}

			if(flag)
			{
				flag=0;
				if((k%b==0 && (k/b)<s) || (k%s==0 && (k/s)<b))
				{
					flag=1;
					return 1;
				}
			}

			if(!flag)
			{
				return 0;
			}
}
int main(int argc, char const *argv[])
{
	l t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		l r,c,m,k,j,area;
		scanf("%lld %lld %lld %lld %lld",&r,&c,&m,&k,&j);
		area = r*c;

		if(m>area)
			printf("No\n");
		else if(m+k>area)
			printf("No\n");
		else if((m+k+j)!=area)
			printf("No\n");
		else
		{
			int flag=0,flag1=0;
			if(m>k)
			{
				if(j>m)
				{
					l temp=j;
					j=m;
					m=temp;
				}
				if(j>k)
				{
					l temp=j;
					j=k;
					k=temp;
				}
			}
			else
			{
				l temp=k;
				k=m;
				m=temp;
				if(j>m)
				{
					temp=j;
					j=m;
					m=temp;
				}
				if(j>k)
				{
					temp=j;
					j=k;
					k=temp;
				}
			}
			// printf("%lld %lld %lld\n",m,k,j );
			l i,s = (r>c)?c:r , b =r+c-s ;
			if(chck(m,k,j,b,s,area)==0)
			{
				if(chck(m,k,j,s,b,area)==0)
					printf("No\n");
				else printf("Yes\n");
			}
			else
				printf("Yes\n");
		}
	}
	return 0;
}