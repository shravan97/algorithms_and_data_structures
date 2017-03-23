#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int m,d,nd=0;
	cin>>m>>d;

	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		nd=31;
	else if(m==2)
		nd=28;
	else
		nd=30;
	nd-=(8-d);
	int w=1;
	w+=(nd/7 + ((nd%7)!=0));

	cout<<w<<endl;

	return 0;
}
