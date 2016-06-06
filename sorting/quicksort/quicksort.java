class quicksort
{
	private static int partition( int arr[] , int start , int end)
	{
		int partition = arr[end-1] , i , pIndex=start;
		for(i=start;i<end-1;i++)
		{
			if(arr[i] < partition)
			{
				int temp;
				temp = arr[pIndex];
				arr[pIndex] = arr[i];
				arr[i] = temp;
				pIndex++;
			}
			
		}

		int temp;
		temp = arr[pIndex];
		arr[pIndex] = arr[end-1];
		arr[end-1] = temp;

		return pIndex;

	}

	private static void quicksort( int arr[] , int start , int end)
	{

		if(start<end)
		{
			int p = partition(arr , start , end);
			quicksort(arr,start,p);
			quicksort(arr , p+1 , end);
		}

	}
	
	public static void main(String[] args) {
		int[] arr= {2,6,7,5,1,3,4};
		quicksort(arr , 0,7);

		for (int i=0;i<7 ;i++ ) 
		{
			System.out.println(Integer.toString(arr[i])+' ');
		}
	}

	
}
