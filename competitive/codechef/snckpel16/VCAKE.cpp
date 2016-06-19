#include <cstdio>
using namespace std;
typedef long long int l;
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
				else if(j>k)
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
				else if(j>k)
				{
					temp=j;
					j=k;
					k=temp;
				}
			}
			// printf("%lld %lld %lld\n",m,k,j );
			l i,s = (r>c)?c:r , b =r+c-s ;
			for(i=1;i<=s;i++)
			{
				if(m%i==0 && (m/i)==b)
				{
					if((i==s && k==0 && j==0) || (i!=s))
					{
						flag=1;
						flag1=1;
						s-=i;
						printf("Yes\n");
						area-=m;
						break;
					}
				}
				else if(m%i==0 && (m/i)<b && i==s)
				{
					flag=1;
					b-=(m/i);
					area-=m;
					break;
				}
			}

			if(flag && flag1==0)
			{
				flag=0;
				for(i=1;i<=s;i++)
			    {
			    	if(k%i==0 && (k/i)==b)
					{
						if((i==s && j==0) || (i!=s))
						{
							flag=1;
							s-=i;
							area-=k;
							printf("Yes\n");
							break;
						}
					}
					else if(k%i==0 && (k/i)<b && i==s)
					{
						flag=1;
						b-=(k/i);
						area-=k;
						printf("Yes\n");
						break;
					}
				}
			}

			if(!flag && !flag1)
			{
				printf("No\n");
			}
		}
	}
	return 0;
}