#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> vec);

int main()
{

	
	shared_ptr<Node> A = shared_ptr<Node>(new Node(5));
	shared_ptr<Node> B = shared_ptr<Node>(new Node(3));
	shared_ptr<Node> C = shared_ptr<Node>(new Node(1));
	A->SetLeftNode(B);
	A->SetRightNode(C);
	A->DebugLog();
	shared_ptr<Node> D = shared_ptr<Node>(new Node(-2));
	D->DebugLog();
	return 0;
}

void printVector(vector<string> vec)
{
		string show = "[";
		for(string data:vec)
			show += data + ",";
		
		if(vec.size() > 0)
			show.pop_back();
		
		show += "]";
		
		cout << show << endl;
}
