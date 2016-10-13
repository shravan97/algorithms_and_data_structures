#include <bits/stdc++.h>
#define max(a,b)((a>b)?a:b)
using namespace std;
int main(int argc, char const *argv[])
{
	int t,count=1;
	cin>>t;
	ofstream ofile;
	ofile.open("out.txt",ios::out);

	while(t--)
	{
		int r,i,j,c,s;
		cin>>r>>c>>s;
		bool a[r][c];
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				a[i][j]=0;
		for(i=0;i<s;i++)
		{
			int r1,c1;
			cin>>r1>>c1;
			a[r1][c1]=1;
		}
		int max_sz = max(r,c);
		int sz=2 , num=r*c-s;
		// cout<<" num b4 start "<<num<<endl;
		for(i=0;i<r;i++)
		{
			for(sz=2;sz<=max_sz;sz++)
			if(i+sz<=r)
			{
				for(j=0;j<c;j++)
				{
					if(j+sz<=c)
					{
						int k,z;
						bool flg=1;
						for(k=i;k<i+sz;k++)
						{
							for(z=j;z<j+sz;z++)
							{
								// cout<<" here at "<<k<<' '<<z<<endl;
								if(a[k][z]!=0)
								{
									flg=0;
									break;
								}
							}
							// if(!flg)
								// break;
							// else
							// {
								// cout<<" sqr with "<<k<<' '<<z<<" and sz "<<sz<<endl; 
								// num++;
							// }
						}

						if(flg)
						{
							// cout<<" sqr with "<<i<<' '<<j<<" and sz "<<sz<<endl;
							num++;
						}
					}

				}
			}
		}

		ofile<<"Case #"<<count<<": "<<num<<'\n';
		count++;

		// cout<<num<<endl;
	}
	return 0;
}