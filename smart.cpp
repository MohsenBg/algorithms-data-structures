#include <iostream>
#include <memory>
#include <string>

using namespace std;


int main()
{
	 unique_ptr<int> data;
	{
		data = unique_ptr<int>(new int(5));
	}
	cout << *data << endl;
	return 0;
}

