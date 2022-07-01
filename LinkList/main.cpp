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
	myList.DebugLog();
	myList.Remove(-2);
	myList.DebugLog();
	myList.ChangeValue(-3,10);
	myList.DebugLog();
	return 0;
}
