#include <iostream>
#include "Sorting.cpp"

void printArray(int *array,int size);
void PrintLine();
void RandomArray(int * array, int size);

int main()
{
	srand((unsigned)time(NULL));

	const int sizeArray = 10;
	int myArray[sizeArray];
	
	
	cout << "------------------------------------\n";
	cout << "BubbleSort" <<endl;
	RandomArray(myArray,sizeArray);
	cout << "Befor:"<< endl;
	printArray(myArray,sizeArray);
	
	cout << "After:"<< endl;
	Sorting::BubbleSort(myArray,sizeArray);
	printArray(myArray, sizeArray);
	

	cout << "------------------------------------\n";
	cout << "QuickSort" << endl;
	RandomArray(myArray,sizeArray);
	cout << "Befor:"<< endl;
	printArray(myArray,sizeArray);
	
	cout << "After:"<< endl;
	Sorting::QuickSort(myArray,sizeArray - 1);
	printArray(myArray, sizeArray);


	cout << "------------------------------------\n";
	cout << "MargeSort" << endl;
	RandomArray(myArray,sizeArray);
	cout << "Befor:"<< endl;
	printArray(myArray,sizeArray);
	
	cout << "After:"<< endl;
	Sorting::MargeSort(myArray,sizeArray);
	printArray(myArray, sizeArray);
	
	return 0;
}

void RandomArray(int * array , int size)
{
	for(int i = 0; i < size ; i++)
	{
		array[i] = rand()%100 ;
	}	
}

void printArray(int *array,int size)
{
		string show = "[";
		for(int i =0; i < size; i++)
			show += to_string(array[i]) + ",";
		
		if(size != 0)
			show.pop_back();
		
		show += "]";
		
		cout << show << endl;
}

void PrintLine()
{
	cout << "-----------------------\n";
}
