#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,i;
	long long int s,d=0;
	scanf("%d %lld",&n,&s);

	for(i=0;i<n;i++)
	{
		char ch[2];
		long long int st;
		scanf("%s %lld",ch,&st);
		if(ch[0]=='+')
			s+=st;
		else
		{
			if(s>=st)
				s-=st;
			else
				d++;
		}

	}
	printf("%lld %lld",s,d );

	return 0;
}