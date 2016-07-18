#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void max_heapify(int *a , int parent_pos , int heap_len)
{
	int largest =parent_pos;
	if(2*parent_pos + 1 < heap_len && *(a+(2*parent_pos+1)) > *(a+parent_pos) )
	{
		largest = 2*parent_pos + 1;
	}
	if(2*parent_pos+2 < heap_len && *(a+(2*parent_pos+2)) > *(a+largest))
	{
		largest = 2*parent_pos+2;
	}

	if(largest!=parent_pos)
	{
		int temp;
		temp = *(a+largest);
		*(a+largest) = *(a+parent_pos);
		*(a+parent_pos) = temp;
		max_heapify(a,largest,heap_len);
	}
}
void build_max_heap(int *a , int heap_len)
{
	int i;
	for(i=(heap_len-2)/2;i>=0;i--)
		max_heapify(a,i,heap_len);
}
void heapsort(int * a , int len)
{
	build_max_heap(a,len);
	while(len>1)
	{
		int temp = *(a+len-1);
		*(a+len-1) = *(a);
		*(a) = temp;
		build_max_heap(a,--len);
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));//Testing using random numbers

	int arr[10000];
	int i;
	for(i=0;i<10000;i++)
		arr[i] = rand()%100000;

	heapsort(arr,10000);
	for(i=0;i<10000;i++)
	{
		printf("%d\n",arr[i] );
	}

	return 0;
}