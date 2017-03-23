#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void reverse(char * str)
{
	long int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp;
temp=str[i];
str[i]=str[len-i-1];
str[len-i-1]=temp;


	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
