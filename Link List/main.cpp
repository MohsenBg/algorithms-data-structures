#include <iostream>
#include "LinkList.cpp"
#include <vector>
using namespace std;

// print "\n\n------------------\n"
void AddLine();

int main()
{
	LinkList myList;
	vector<int>data = {5,8,1,20,4,5,3};
	
	for(int i: data)
	{	
		cout << "AddElement"<<"("<< i <<")" << endl;
		myList.AddElement(i);
		myList.DebugLog();
	}

	AddLine();
	cout << "Remove(-2)" << endl;
	myList.Remove(-2);
	myList.DebugLog();


	cout << "Remove()" <<endl;
	myList.Remove();
	myList.DebugLog();

	cout  << "Remove(0)" << endl;
	myList.Remove(0);
	myList.DebugLog();

	AddLine();
	cout << "Insert(85,-3)" << endl;
	myList.Insert(85,-3);
	myList.DebugLog();

	cout << "Insert(50)" <<endl;
	myList.Insert(50);
	myList.DebugLog();

	cout  << "Insert(69,0)" << endl;
	myList.Insert(69,0);
	myList.DebugLog();

	AddLine();
	cout << "ChangeValue(14,-3)" << endl;
	myList.ChangeValue(14,-3);
	myList.DebugLog();

	cout << "ChangeValue(30,2)" <<endl;
	myList.ChangeValue(30,2);
	myList.DebugLog();

	cout  << "ChangeValue(85,0)" << endl;
	myList.ChangeValue(85,0);
	myList.DebugLog();


	cout << "Find()" << endl;
	cout << myList.Find(85) <<endl;

	AddLine();
	cout << "Count(): " << myList.Count() << endl;
	
	AddLine();
	cout << "begin(): " << myList.begin().value << endl;
	
	AddLine();
	cout << "end(): "   << myList.end().value  <<  endl;
	
	AddLine();
	cout << "AtIndex(5):  " << myList.AtIndex(5)->value  << endl;
	cout << "AtIndex(-1): " << myList.AtIndex(-1)->value << endl;
	cout << "AtIndex(0):  " << myList.AtIndex(0)->value  << endl;
	

	AddLine();
	myList.DebugLog();
	cout << "Reverce()" << endl;
	myList.Reverce();
	myList.DebugLog();
	return 0;
}


void AddLine()
{
	cout << "\n---------------------------- \n\n";
}
