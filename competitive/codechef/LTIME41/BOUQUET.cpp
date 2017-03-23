#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll mg,my,mr,og,o_r,oy,pg,pr,py;
		cin>>mg>>my>>mr>>og>>oy>>o_r>>pg>>py>>pr;
		
		ll arr[15];
		arr[0]= mg+my+mr;
		arr[1]=og+o_r+oy;
		arr[2]=pg+pr+py;
		arr[3] = mg+og+pg;
		arr[4] = my+oy+py;
		arr[5] = mr+o_r+pr;
		arr[6] = mr;
		arr[7] = my;
		arr[8] = mg;
		arr[9] = oy;
		arr[10] = o_r;
		arr[11] = og;
		arr[12] = pg;
		arr[13] = py;
		arr[14] = pr;

		ll l=-1;

		for(int i=0;i<15;i++)
		{
			if(arr[i]>l)
				l=arr[i];
		}

		if(l!=0)
		{
			if(l&1)
				cout<<l<<endl;
			else
				cout<<l-1<<endl;
		}
		else
			cout<<l<<endl;
		
		
	}
	return 0;
}