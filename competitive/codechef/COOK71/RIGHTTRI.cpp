#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int l;
int main(int argc, char const *argv[])
{
	l t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int h,s;
		scanf("%lld %lld",&h,&s);

		if((h*h)<(4*s))
			printf("-1\n");
		else
		{
			float s1 = ((float)(h*h)+((float)sqrt(pow(h,4) - 16*s*s)))/2.0;
			float s2 = ((float)(h*h)-((float)sqrt(pow(h,4) - 16*s*s)))/2.0;
			s1=(float)sqrt(s1);
			s2=(float)sqrt(s2);
			printf("%f %f %f\n",s1,s2,(float)(h) );
		}
	}
	return 0;
}