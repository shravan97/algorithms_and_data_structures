#include <iostream>
using namespace std;

typedef long long int ll;

ll partition(ll *arr , ll start , ll end) //Partitions based on the element at end index
{
	/* --Partition algorithm--
	 > Initialize partition index as start
	 > Begin from start 
	 > Then compare with the end indexed element
	 > If current element is lesser than the end element 
	 	-> Then swap it with the partition index element 
	 	-> Then increment partition index by 1
	 > Do this from i=start to i=end-2
	 > Then swap the partition indexed element and the end indexed element 

	 */

	ll i , pIndex = start;

	for(i=start;i<end-1;i++)
	{
		ll temp;

		if(*(arr+i) < *(arr + end -1))
		{
			temp = *(arr+i);
			*(arr+i) = *(arr+pIndex);
			*(arr+pIndex) = temp;
			pIndex++;
		}

	}

	ll temp;

	temp = *(arr + end - 1);
	*(arr + end - 1) = *(arr + pIndex);
	*(arr + pIndex) = temp;


	return pIndex;
}

void quicksort(ll *arr , ll start , ll end)
{
	/*  --Quicksort algorithm--
	> Partition the array with the last element as pivot
	> Then recursively call quicksort function by passing in appropriate start and end index

	*/
	
	if(start<end)
	{
		for(ll i=start;i<end;i++)
		{
			cout<<arr[i]<<' ';
		}
		cout<<'\n';

		ll p = partition(arr , start , end);
		quicksort(arr , start, p);
		quicksort(arr , p+1 , end);
	}
}

int main()
{
	ll arr[7] = {2,6,7,5,1,3,4};

	quicksort(arr , 0 , 7);

	for (int i = 0; i < 7; ++i)
	{
		cout<<arr[i]<<' ';
	}

return 0;
}