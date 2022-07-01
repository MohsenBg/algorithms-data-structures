#include <iostream>
#include "LinkList.cpp"

using namespace std;

int main()
{
	LinkList myList;
	myList.AddElement(5);
	myList.AddElement(8);
	myList.AddElement(1);
	myList.AddElement(20);
	myList.AddElement(4);
	myList.AddElement(5);
	myList.AddElement(3);
	cout << myList.GetValues()[myList.Count()-1] << endl;
	return 0;
}
