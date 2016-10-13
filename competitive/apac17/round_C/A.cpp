#include <bits/stdc++.h>
#define max(a,b)((a>b)?a:b)
using namespace std;
double move(vector< std::vector<char> > &a,int r,int c , int mv,double p,double q,int rmax,int cmax)
{
	// cout<<" here  at  "<<r<<' '<<c<<" and "<<mv<<endl;
	if(mv==0)
		if(r>=0&&r<rmax && c>=0&& c<cmax)
			return (a[r][c]=='.')?q:p;
		else return 0.00;

	double k1=0.00,k2=0.00,k3=0.00,k4=0.00;
	if(r>=0)
		k1 = move(a,r-1,c,mv-1,p,q,rmax,cmax);
	else 
		return 0;

	if(c>=0)
		k2=move(a,r,c-1,mv-1,p,q,rmax,cmax);
	else return 0;
	if(r<rmax)
		k3=move(a,r+1,c,mv-1,p,q,rmax,cmax);
	else return 0;

	if(c<cmax)
		k4=move(a,r,c+1,mv-1,p,q,rmax,cmax);
	else return 0;

	if(a[r][c]=='.')
	{
		cout<<" at "<<r<<' '<<c<<"  .   : "<<q+max(max(k1,k2),max(k3,k4))<<endl; 
		return q+max(max(k1,k2),max(k3,k4));
	}
	cout<<" at "<<r<<' '<<c<<"  A   : "<<p+max(max(k1,k2),max(k3,k4))<<endl;
	return p+max(max(k1,k2),max(k3,k4));

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	ofstream ofile;
	ofile.open("out.txt",ios::out);

	while(t--)
	{
		int r,c,rs,cs,s;
		cin>>r>>c>>rs>>cs>>s;
		std::vector< std::vector<char> > a;
		double p,q;
		cin>>p>>q;

		for(int i=0;i<r;i++)
		{
			std::vector<char> v;
			for(int j=0;j<c;j++)
			{
				char k;
				cin>>k;
				v.push_back(k);
			}
			a.push_back(v);
		}

		cout<<move(a,rs,cs,s,p,q,r,c)-((a[rs][cs]=='.')?q:p)<<endl;

	}
	return 0;
}