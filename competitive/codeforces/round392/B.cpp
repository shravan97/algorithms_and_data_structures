#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	map <char,ll> m;
	char s0='0',s1='0',s2='0',s3='0';

	for(ll i=0;i<s.size();i++)
	{
		// ll r1=0,g1=0,b1=0,y1=0;
		// if(s[i]=='!')
		// {
		// 	ll cur=0;
		// 	if(i-4>=0)
		// 	{
		// 		s[i]=s[i-4];
		// 		if(r1==0)
		// 	{
		// 		s[i]='R';
		// 		r++;
		// 	}
		// 	else if(g1==0)
		// 	{
		// 		s[i]='G';
		// 		g++;
		// 	}
		// 	else if(b1==0)
		// 	{
		// 		s[i]='B';
		// 		b++;
		// 	}
		// 	else if(y1==0)
		// 	{
		// 		s[i]='Y';
		// 		y++;
		// 	}

		// 	}
		// 	for(ll j=cur;j<=i+3;j++)
		// 	{
		// 		// cout<<s[i]<<' ';
		// 		if(s[j]=='R')
		// 			r1=1;
		// 		else if(s[j]=='G')
		// 			g1=1;
		// 		else if(s[j]=='B')
		// 			b1=1;
		// 		else if(s[j]=='Y')
		// 			y1=1;
		// 	}
		// 	if(r1==0)
		// 	{
		// 		s[i]='R';
		// 		r++;
		// 	}
		// 	else if(g1==0)
		// 	{
		// 		s[i]='G';
		// 		g++;
		// 	}
		// 	else if(b1==0)
		// 	{
		// 		s[i]='B';
		// 		b++;
		// 	}
		// 	else if(y1==0)
		// 	{
		// 		s[i]='Y';
		// 		y++;
		// 	}
				
		// }
		if(i%4==0)
		{
			if(s[i]!='!')
				s0=s[i];
		}
		if(i%4==1)
		{
			if(s[i]!='!')
				s1=s[i];
		}
		if(i%4==2)
		{
			if(s[i]!='!')
				s2=s[i];
		}
		if(i%4==3)
		{
			if(s[i]!='!')
				s3=s[i];
		}
		
	}

	map <char,bool> m1;

	if(s0!='0')
		m1[s0]=1;
	if(s1!='0')
		m1[s1]=1;
	if(s2!='0')
		m1[s2]=1;
	if(s3!='0')
		m1[s3]=1;

	if(s3=='0')
	{
		if(!m1['R'])
			s3='R';
		else if(!m1['G'])
			s3='G';
		else if(!m1['B'])
			s3='B';
		else if(!m1['Y'])
			s3='Y';
		m1[s3]=1;
	}
	if(s2=='0')
	{
		if(!m1['R'])
			s2='R';
		else if(!m1['G'])
			s2='G';
		else if(!m1['B'])
			s2='B';
		else if(!m1['Y'])
			s2='Y';
		m1[s2]=1;
	}
	if(s1=='0')
	{
		if(!m1['R'])
			s1='R';
		else if(!m1['G'])
			s1='G';
		else if(!m1['B'])
			s1='B';
		else if(!m1['Y'])
			s1='Y';
		m1[s1]=1;
	}
	if(s0=='0')
	{
		if(!m1['R'])
			s0='R';
		else if(!m1['G'])
			s0='G';
		else if(!m1['B'])
			s0='B';
		else if(!m1['Y'])
			s0='Y';
		m1[s0]=1;
	}
	
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='!')
		{
			if(i%4==0)
				m[s0]++;
			else if(i%4==1)
				m[s1]++;
			else if(i%4==2)
				m[s2]++;
			else if(i%4==3)
				m[s3]++;
			
		}
	}
	
	
	// cout<<s<<endl;
	cout<<m['R']<<' '<<m['B']<<' '<<m['Y']<<' '<<m['G']<<endl;
	return 0;
}
