#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

int post_fix(char ep[] , int index)
{
	std::map<char, int> ops;
	stack <char> op;
	ops['^']=100;
	ops['/']=75;
	ops['*']=75;
	ops['-']=25;
	ops['+']=25;

	int i;
	// printf("HOLA %c %d\n",ep[1],ops['^']);
	// cout<<strlen(ep)<<'\n';

	for(i=index;i<strlen(ep) && ep[i]!=')';)
	{
		if(ep[i]=='(')
			i=post_fix(ep , i+1);
		else if(ep[i]=='^'||ep[i]=='*'||ep[i]=='/'||ep[i]=='+'||ep[i]=='-')
		{
			if(!op.empty())
			{
				if(ops[op.top()]>=ops[ep[i]])
				{
					printf("%c",op.top());
					op.pop();
					op.push(ep[i]);
				}
				else op.push(ep[i]);
			}
			else op.push(ep[i]);
			i++;
		}
		else 
		{
			printf("%c",ep[i]);
			i++;
		}
	}

	while(!op.empty())
	{
		printf("%c",op.top());
		op.pop();
	}
	return i+1;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		char ep[401];
		scanf("%s",ep);
		int z = post_fix(ep,0);
		printf("\n");
	}
	return 0;
}