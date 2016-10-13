#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	int a,b,n;
	scanf("%d %d",&a,&b);
	scanf("%d",&n);
	int x[n],y[n],v[n],i;
	float min_time = -1.0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x[i],&y[i],&v[i]);
		float time = (float)(sqrt((a-x[i])*(a-x[i]) + (b-y[i])*(b-y[i])))/(float)(v[i]);
		if(time<min_time || min_time==-1.0)
			min_time=time;

	}
	printf("%f\n",min_time );
	return 0;
}