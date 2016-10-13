#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n;
	string s;
	cin>>n;
	cin>>s;
	if(n>26)
	{
		cout<<-1<<'\n';
		return 0;
	}
	set <char> st;

	for(long long int i=0;i<n;i++)
	{
		st.insert(s[i]);
	}
	int n_uniq = st.size();
	
	cout<<n-n_uniq<<'\n';
	return 0;
}