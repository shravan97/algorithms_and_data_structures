#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	while(1)
	{
		int n,count=0;
		scanf("%d",&n);
		if(n==0)break;
		char a[201];
		scanf("%s",a);
		while(count<n)
		{
			printf("%c",a[count] );
			for(int i=count+2*(n-count)-1;i<strlen(a);i+=2*(n-count)-1)
			{
				printf("%c",a[i]);
				i+=2*(count)+1;
				if(i<strlen(a))
				printf("%c",a[i] );
			}
			count++;
		}
		cout<<'\n';
	}
	return 0;
}