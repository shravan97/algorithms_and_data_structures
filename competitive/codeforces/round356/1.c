#include <stdio.h>
int main()
{
	int t[5] ,i , j , cur_sum=0, max_sum=0 , tot_sum=0;
	for(i=0;i<5;i++)
	{
		scanf("%d",&t[i]);
		tot_sum+=t[i];
	}

	for(i=0;i<5;i++)
	{
		int match=0;
		for(j=i+1;j<5;j++)
		{
			if(t[j]==t[i])
			{
				if(match==0)
				{
					cur_sum=2*t[i];
					match++;
				}
				else if(match==1)
				{
					cur_sum+=t[i];
					match++;
				}
			}
		}

		if(cur_sum > max_sum )
			max_sum=cur_sum;

	}

	printf("%d", tot_sum - max_sum);
	return 0;
}