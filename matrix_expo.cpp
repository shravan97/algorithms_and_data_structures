#include <iostream>
using namespace std;
//Fibonacci using matrix exponentiation
struct mat
{
	long long int a , b, c ,d;
};

mat mult(mat m1 , mat m2)
{
	mat res ;
	res.a = m1.a*m2.a+m1.b*m2.c;
	res.b = m1.a*m2.b+m1.b*m2.d;
	res.c = m1.c*m2.a+m1.d*m2.c;
	res.d = m1.c*m2.b+m1.d*m2.d;

	return res;
}
mat pow(mat m1 , long long int k)
{
	if(k==1)
		return m1;
	else
	{
		mat t = pow(m1,k/2);

		if(k%2)
		{
			
			return mult(mult(t,t) , m1);
		}
		else
		{
			return mult(t,t);
		}
	}

}

long long int fibo(long long int n)
{
	mat f = {1,1,1,0};

	if(n==0)
		return 0;
	if(n==1)
		return 1;

	mat res = pow(f,n-1);
	return res.a;
}
main()
{
	long long int n;int t , i;

	cin>>t;

	for(i=0;i<t;i++)
	{
		cin>>n;
		if(n==0)
			cout<<0;
		else if(n==1 || n==2)
			cout<<1;
		else
			cout<<fibo(n);

	}

	return 0;
}