#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#define min(a,b)((a<b)?a:b)
#define MAX 10000000000
using namespace std;
typedef long long int ll;

string rev(string s , ll len)
{
	ll i;
	for(i=0;i<len/2;i++)
		s[i] = s[len-i-1];
	return s;
}

int main(int argc, char const *argv[])
{
	ll n,i;
	cin>>n;
	ll c[n];
	
	for (i = 0; i < n; ++i)
		cin>>c[i];

	string s[n];
	ll mins[n][2];
	bool flag=0;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		if(i!=0)
		{
			if(!flag && (s[i].size() < s[i-1].size()))
			{
				flag=1;
			}
			else if(!flag)
			{
				// cout<<" i "<<i<<'\n';
				string rs1 = rev(s[i],s[i].size()) , rs2 = rev(s[i-1],s[i-1].size());
				// cout<<rs1<<' '<<rs2<<endl;
				if(s[i]<s[i-1])
				{
					ll done=0,done2=0, min1 = MAX,min2=MAX,min3=MAX;
					if(rs1 >= s[i-1])
					{
						done++;
						if(mins[i-1][0]!=10000000000)
						min1 = mins[i-1][0]+c[i];
						// cout<<"h1 "<<mins[i-1][0]<<' '<<c[i]<<endl;
					}
					if(rs2 <= s[i])
					{
						done++;
						done2=1;
					 	mins[i][0] = mins[i-1][1];
					 	// cout<<"h2 "<<mins[i-1][1]<<' '<<c[i-1]<<endl;
					}
					if(rs2 <= rs1)
					{
						done++;
						if(mins[i-1][1]!=10000000000)
						min3 = mins[i-1][1] + c[i];
						// cout<<"h3 "<<mins[i-1][1]<<' '<<c[i-1]<<endl;
					}
					if(done==0) flag=1;
					mins[i][1] = min(min(min1,min2),min3);
					// cout<<mins[i][1]<<'h'<<'\n';
					if(!done2)
						mins[i][0] = 10000000000;
					// cout<<" for i "<<i<<' '<<mins[i][0]<<" & "<<mins[i][1]<<endl;

				}
				else
				{
					mins[i][0] = mins[i-1][0];
					ll min1=MAX , min2=MAX;
					if(rs2 <= s[i])
						mins[i][0] = min(mins[i][0],mins[i-1][1]);
					if(rs1 >= s[i-1])
					{
						if(mins[i-1][0]!=10000000000)
							min1 = c[i]+mins[i-1][0];
						else min1 = 10000000000;
					}
					if(rs2 <= rs1)
						if(mins[i-1][1]!=MAX)
							min2 = c[i]+mins[i-1][1];
						else min2 = MAX;

					mins[i][1] = min(min1,min2);
					// cout<<" for i "<<i<<' '<<mins[i][0]<<" & "<<mins[i][1]<<endl;
				}
			}
		}
		else
		{
			mins[0][0]=0;
			mins[0][1]=c[0];
			// cout<<0<<' '<<c[0]<<'\n';
		}
	}
	// cout<<1000000000<<'\n';
	if(flag) cout<<-1<<'\n';
	else
		cout<<min(mins[n-1][0],mins[n-1][1])<<'\n';
	return 0;
}