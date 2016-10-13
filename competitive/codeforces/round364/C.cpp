#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,i,len,no_uniq=0,u_count=0,start_index=0,min_steps=INT_MAX;
	string s;
	cin>>n;
	cin>>s;
	len = s.length();
	std::map<char, bool> chars , chars_chck;

	for(i=0;i<len;i++)
	{
		if(!chars[s[i]])
		{
			no_uniq++;
		}
		chars[s[i]]=1;
	}

	for(i=0;i<len;i++)
	{
		if(!chars_chck[s[i]])
			u_count++;

		chars_chck[s[i]]=1;

		if(u_count==no_uniq)
		{
			auto map <char ,bool> ch;
			ll un=0,j;

			for(j=i;j>=start_index;j--)
			{
				if(!ch[s[j]])
					un++;
				ch[s[j]]=1;
				// cout<<un<<'';
				if(un==no_uniq)
				{
					start_index = j;
					break;
				}

			}
			// cout<<start_index<<'\n'<<i<<'\n';

			if(min_steps > i-start_index+1)
				min_steps = i-start_index+1;
			start_index = i;
			u_count=1;
			chars_chck.erase(chars_chck.begin(),chars_chck.end());
			chars_chck[s[i]]=1;
		}
	}
	cout<<min_steps<<'\n';
	return 0;
}
/* Not satisfying : 
	11
	abcccdaabcd
*/