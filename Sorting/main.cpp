#include <iostream>
#include "Sorting.cpp"
#include <chrono>

using namespace std;

enum TIME
{
	MS,
	US,
	NS
};

void printArray(int *array, int size, int max);
void PrintLine();
void RandomArray(int *array, int size, int range);
chrono::steady_clock::time_point GetTimeNow();

void CalcTime(
	chrono::steady_clock::time_point begin,
	chrono::steady_clock::time_point end, TIME unit);

int main()
{
	srand((unsigned)time(NULL));

	const int sizeArray = 500;
	const int range = 1000;
	const TIME unit = US;
	const int countNumber = 10;
	int myArray[sizeArray];

	chrono::steady_clock::time_point begin;
	chrono::steady_clock::time_point end;

	cout << "------------------------------------\n";
	cout << "BubbleSort" << endl;
	RandomArray(myArray, sizeArray, range);
	cout << "Befor:" << endl;
	printArray(myArray, sizeArray, countNumber);

	cout << "After:" << endl;
	begin = GetTimeNow();
	Sorting::BubbleSort(myArray, sizeArray);
	end = GetTimeNow();
	printArray(myArray, sizeArray, countNumber);
	CalcTime(begin, end, unit);

	cout << "------------------------------------\n";
	cout << "SelectionSort" << endl;
	RandomArray(myArray, sizeArray, range);
	cout << "Befor:" << endl;
	printArray(myArray, sizeArray, countNumber);

	cout << "After:" << endl;
	begin = GetTimeNow();
	Sorting::SelectionSort(myArray, sizeArray);
	end = GetTimeNow();
	printArray(myArray, sizeArray, countNumber);
	CalcTime(begin, end, unit);

	cout << "------------------------------------\n";
	cout << "InsertionSort" << endl;
	RandomArray(myArray, sizeArray, range);
	cout << "Befor:" << endl;
	printArray(myArray, sizeArray, countNumber);

	cout << "After:" << endl;
	begin = GetTimeNow();
	Sorting::InsertionSort(myArray, sizeArray);
	end = GetTimeNow();
	printArray(myArray, sizeArray, countNumber);
	CalcTime(begin, end, unit);

	cout << "------------------------------------\n";
	cout << "QuickSort" << endl;
	RandomArray(myArray, sizeArray, range);
	cout << "Befor:" << endl;
	printArray(myArray, sizeArray, countNumber);

	cout << "After:" << endl;
	begin = GetTimeNow();
	Sorting::QuickSort(myArray, sizeArray - 1);
	end = GetTimeNow();
	printArray(myArray, sizeArray, countNumber);
	CalcTime(begin, end, unit);

	cout << "------------------------------------\n";
	cout << "MargeSort" << endl;
	RandomArray(myArray, sizeArray, range);
	cout << "Befor:" << endl;
	printArray(myArray, sizeArray, countNumber);

	cout << "After:" << endl;
	begin = GetTimeNow();
	Sorting::MargeSort(myArray, sizeArray);
	end = GetTimeNow();
	printArray(myArray, sizeArray, countNumber);
	CalcTime(begin, end, unit);

	return 0;
}

void RandomArray(int *array, int size, int range = 100)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % range;
	}
}

void printArray(int *array, int size, int max = -1)
{
	string show = "[";
	for (int i = 0; i < size; i++)
	{
		show += to_string(array[i]) + ",";
		if (i == max-1)
		{
			show += "...+" + to_string(size - (i + 1)) + " item ,";
			break;
		}
	}
	if (size != 0)
		show.pop_back();

	show += "]";

	cout << show << endl;
}

void PrintLine()
{
	cout << "-----------------------\n";
}

chrono::steady_clock::time_point GetTimeNow()
{
	return chrono::steady_clock::now();
}

void CalcTime(
	chrono::steady_clock::time_point begin,
	chrono::steady_clock::time_point end, TIME unit = MS)
{

	string show = "Time:";

	switch (unit)
	{
	case MS:
		show += to_string(chrono::duration_cast<chrono::milliseconds>(end - begin).count()) + "[ms]";
		break;

	case US:
		show += to_string(chrono::duration_cast<chrono::microseconds>(end - begin).count()) + "[µs]";
		break;

	case NS:
		show += to_string(chrono::duration_cast<chrono::nanoseconds>(end - begin).count()) + "[ns]";
		break;
	}
	cout << show << endl;
}
