#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	string s,s_req;
	cin>>s;
	long long int len = s.length() , i=0,dot=-1,e_val=-1,shift=0;
	long long int len2=len;

	for(i=0;i<len;i++)
	{
		if(s[i]=='.') dot=i;
		if(s[i]=='e') 
		{
			e_val=i;
		}
		else if(e_val!=-1)
			shift=shift*10 + ((char)(s[i]) - 48);
	}

	while(s[0]=='0' && len2!=1 && s[1]!='.' )
	{
		s.erase(s.begin());
		len2--;
	}
	len = len2;


	if(dot==-1)
	{
		if(e_val==-1)
		{
			cout<<s;
			return 0;
		}
		cout<<s.substr(0,e_val);
		for(int j=0;j<shift;j++)
			cout<<0;
		return 0;
	}


	if(shift > (e_val-dot-1))
		shift = (e_val-dot-1);
	s.erase(find(s.begin(),s.end(),'.'));
	s.insert(s.begin()+dot+shift , '.');
	s_req = s.substr(0,e_val);
	if(s_req[s_req.length() - 1]=='.')
		s_req = s_req.substr(0,s_req.length()-1);

	cout<<s_req;

	return 0;
}