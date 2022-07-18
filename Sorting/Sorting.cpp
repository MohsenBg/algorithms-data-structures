#include "iostream"
#include <memory>

using namespace std;


class Sorting
{
	private:
	
		static int Partition(int * array , int high,  int low)
		{
			int povit = array[low];
			int lp = low ;
			int rp = high; 
			while(lp < rp)
			{
				//cout << "lp:" << lp << "rp:" << rp << endl;
				while(povit >= array[lp])
					lp++;
			
				while(povit < array[rp])
					rp--;
			
				if(lp < rp)
					swap(array[lp],array[rp]);
			}	

			swap(array[rp],array[low]);
	
			return rp;
		}


		static	void Marge(int* array,int *leftSide,int sizeLeft,int* rightSide,int sizeRight)
		{
			int i = 0, j = 0, k = 0; 
				
			while(i < sizeLeft && j < sizeRight)
			{
				if(leftSide[i] < rightSide[j])
				{
					array[k] = leftSide[i];
					i++;
				}
				
				else
				{
					array[k] = rightSide[j];
					j++;
				}
			
				k++;
			}


			for(; i < sizeLeft; i++){

				array[k] = leftSide[i];
				k++;
			}
	
			
			for(; j < sizeRight; j++)
			{
				array[k] = rightSide[j];
				k++;
			}
					
		}	
	

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

		static void QuickSort(int * array, int high, int low = 0)
		{
				
			if(high > low)
			{
				int rp = Partition(array,high,low);
				QuickSort(array,rp-1,low);
				QuickSort(array,high,rp+1);
			}

		}

		static void MargeSort(int *array, int size)
		{
			if(size < 2)
				return;
	
			int mid = size/2;
	
			int *leftSide = new int[mid]; 
			int *rightSide = new int[size-mid]; 
		
			for(int i = 0; i < mid ; i++)
				leftSide[i] = array[i];
		
			for(int i=mid; i<size; i++)
				rightSide[i-mid] = array[i];
		
			MargeSort(leftSide,mid);
			MargeSort(rightSide,size-mid);
			Marge(array,leftSide, mid,rightSide,size-mid);

			delete[] leftSide;
			delete[] rightSide;
		}

		static void SelectionSort(int * array , int size)
		{
			for(int i = 0; i < size; i++)
			{
				int min = i;
				for(int j=i+1; j < size; j++)
				{
					if(array[min] > array[j])
						min = j;
				}
				swap(array[min],array[i]);
			}
		}
		static void InsertionSort(int *array, int size)
		{
			for(int i = 1; i < size; i++)
			{
				int current = array[i];
				int j = i-1;
				while(j >=0 && array[j] > current)
				{
					array[j+1] = array[j];
					j--;
				}		
				array[j+1] = current;
			}
		}
};
