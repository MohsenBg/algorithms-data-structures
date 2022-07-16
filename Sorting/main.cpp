#include <iostream>
#include "Sorting.cpp"

void printArray(int *array,int size);
void PrintLine();

int main()
{
	int myArray[10] = {19, 10, 8, 17, 9, 15, 12, 47, 52, 36};
	Sorting::BubbleSort(myArray,10);
	printArray(myArray, 10);
	return 0;
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
