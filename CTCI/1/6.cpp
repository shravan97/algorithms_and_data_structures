#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll m1[4][2];
void rotate(ll m[2][4],int r,int c)
{
	/*
		1 2 3 4
		5 6 7 8

		5 1
		6 2
		7 3
		8 4 
	*/

	for(int j=0;j<c;j++)
	{
		for(int i=r-1;i>=0;i--)
			m1[j][r-i-1]=m[i][j];

	}
}

void rotate_inplace(int m[3][3])
{
	/*
	1 2 3
	4 5 6
	7 8 9

	7 4 1 |  1 4 7
	8 5 2 |  2 5 8
	9 6 3 |	 3 6 9

	1 2 3 4 | 4 3 2 1
	5 6 7 8 | 8 7 6 5
	9 1 2 3 | 3 2 1 9
	4 5 6 7 | 7 6 5 4

	1 5 9 4
	2 6 1 5
	3 7 2 6
	4 8 3 7

	*/

	// Transpose
	for(int i=0;i<3;i++)
	{
		for(int j=i;j<3;j++)
		{
			int temp=m[i][j];
			m[i][j]=m[j][i];
			m[j][i]=temp;
		}
	}

	//mirror
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3/2;j++)
		{
			int temp=m[i][j];
			m[i][j]=m[i][3-j-1];
			m[i][3-j-1]=temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int m[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	rotate_inplace(m);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<m[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
