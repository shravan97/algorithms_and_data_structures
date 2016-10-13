#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,c=1;
	cin>>t;
	ofstream ofile;
	ofile.open("out.txt",ios::out);
	while(t--)
	{
		std::cin.sync_with_stdio(false);
		int n,i,num_diff=0;
		string ldr="";
		cin>>n;
		fflush(stdin);
		for(i=0;i<n+1;i++)
		{
			set<char> st;
			string s;
			getline(cin,s);
			for(int j=0;j<s.length();j++)
				if(s[j]!=' ')
					st.insert(s[j]);
			if(st.size() > num_diff)
			{
				num_diff = st.size();
				ldr=s;
			}
			else if(st.size() == num_diff)
			{
				if(s<ldr)
					ldr = s;
			}
			// if(s.length() > ldr.length())
			// 	ldr = s;
			// else if(s.length() == ldr.length())
			// 	if(s < ldr)
			// 		ldr=s;
			// cout<<i<<'\n';
		}
		cout<<ldr<<'\n';
		ofile<<"Case #"<<c<<": "<<ldr<<'\n';
		c++;
	}
	return 0;
}