#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void validate(char s[] , std::vector<long long int> &arr)
{
	if(s[0]=='i')
	{
		long long int t=0;
		for(int i=7;i<strlen(s);i++)
			t=t*10 + ((int)s[i] - 47);
		arr.push_back(t);
	}
	else if(s[0]=='g')
	{
		long long int t=0;
		for(int i=7;i<strlen(s);i++)
			t=t*10 + ((int)s[i] - 47);
		if(arr.size()!=0)
		{
			sort(arr.begin(), arr.end());
			if(t<arr[0])
			{
				printf("insert %lld\n",t );
				arr.push_back(t);
			}
			else if(t>arr[0])
			{
				while(t<arr[0])
				{
					arr.erase(arr.begin());
				}
				if(t!=arr[0])
				{
					arr.push_back(t);
					printf("insert %lld\n",t);
				}
			}
		}		
	}
	else
	{
		if(arr.size()==0)
		{
			printf("insert 1\n");
		}
		else
		{
			sort(arr.begin(), arr.end());
			arr.erase(arr.begin());
		}
	}
}

int main(int argc, char const *argv[])
{
	long int n,count;
	scanf("%ld",&n);
	count=n;
	char s[100000][25];
	for(long int i=0;i<n;i++)
		scanf("%s %lld",s[i]);
	std::vector<long long int> arr;

	for(long int i=0;i<n;i++)
	{
		validate(s[i],arr);
		printf("%s\n",s[i] );
	}
	return 0;
}