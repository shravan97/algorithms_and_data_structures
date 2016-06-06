class mergesort 
{
	private static void merge(int arr[] , int start , int mid , int end)
	{
		int left[] = new int [mid-start+1];
		int right[] = new int[end-mid] ;
		int i, j;
		for (i=0;i<mid-start+1;i++)
			left[i]=arr[start+i];
		for(j=0;j<end-mid;j++)
			right[j]=arr[mid+j+1];

		int k=start;
		i=0;
		j=0;

		while(i<(mid-start+1) && j<(end-mid))
		{
			if(left[i]<=right[j])
			{
				arr[k++]=left[i];
				i++;
			}
			else
			{;
				arr[k++]=right[j];
				j++;
			}
		}

		while(i<(mid-start+1))
		{
			arr[k++]=left[i];
			i++;
		}
		while(j<(end-mid))
		{
			arr[k++]=right[j];
			j++;
		}

		// System.out.println(mid);
	}

	private static void MergeSort(int arr[] , int start , int end)
	{
		if(start < end)
		{
			int mid = (start + end)/2;
			MergeSort(arr,start,mid);
			MergeSort(arr,mid+1,end);
			merge(arr , start , mid , end);
			// System.out.println(start + " " + end);
		}
	}	
	
	public static void main(String[] args)
	{
		int arr[]={7,1,4,5,2},i;
		MergeSort(arr,0,4);

		for(i=0;i<5;i++)
			System.out.println(arr[i]);

	}
}