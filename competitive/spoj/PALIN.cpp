#include <cstdio>
#include <cstdlib>
#include <cstring>
#define n 1000001
using namespace std;
int main(int argc, char const *argv[])
{
	long long int t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		char * a;
		a = new char [n];
		scanf("%s",a);

		bool inc=0;
		long long int len = strlen(a),i=len-1;
		if(a[0]=='0' && len>1)
		{
			long long int pos=0;
			while(pos<strlen(a) && a[pos]=='0')
				pos++;
		long long int start=pos, end=len-1,p=start;
		char temp[n];
		memset(temp,'0',end-start+1);
		while(p<=end)
		{
			temp[p-start]=a[p];
			p++;
		}
		delete a;
		a = new char [end-start+1];
		p=0;
		while(p<(end-start+1))
		{
			a[p]=temp[p];
			p++;
		}
		
		len = strlen(a);
		i=len-1;

		}
		
		for(;i>=0;i--)
		{
			if(i>=((len%2)?(len/2 +1):len/2))
			{
				if(a[i]<a[len-1-i] && inc!=1)
					inc=1;
				else if(a[i]>a[len-1-i] && inc==1)
					inc=0;
				a[i]=a[len-1-i];
			}
			else if(!inc)
			{
				if(a[i]=='9')
				{
					long long int k=i;
					while(1)
					{
						if(k>0&&a[k]=='9')
						{
							a[k]='0';
							a[len-1-k]='0';
						}
						else
							break;
						k--;
					}

					if(k==0&&a[0]=='9')
					{
						memset(a,'0',len+1);
						a[0]='1';
						i=strlen(a);
						len =i;
						inc=0;
					}
					else
					{
						a[k]+=1;
						a[len-1-k]=a[k];
						inc=1;
					}
				}
				else
				{
					a[i]+=1;
					a[len-1-i]=a[i];
					inc=1;
				}
			}
			else
			{
				a[len-1-i]=a[i];
			}
		}

		printf("%s\n",a );
	}
	return 0;
}