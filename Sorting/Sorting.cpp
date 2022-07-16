#include "iostream"
#include <memory>

using namespace std;


class Sorting
{
	public:
	static void BubbleSort(int *array,int size)
	{
		for(int i = 0; i < size ; i++)
		{	
			bool isSwapped = false;

			for(int j = 0; j< size-i-1 ; j++)
			{
				if(array[j] > array[j+1])
				{
					swap(array[j],array[j+1]);
					isSwapped = true;
				}
			}

			if(!isSwapped)
				break;
		}
	}

	static void QuickSort(int * array,int low,int high)
	{
		int mid = (low+high)/2;
		int pivot = array[mid];
		
		int i = low;
		int j = high;

		while(j > i)
		{
			if(array[i] <= pivot)
			{
				while(array[j] > pivot && j > i)
					j--;
			
				if(j > i)
					swap(array[i],array[j]);
				else
					swap(pivot,array[j]);
			}
			i++;
		}
		if(low < high)
		{
			QuickSort(array,low,j);	
			QuickSort(array,j+1,high);
		};
	}

};
