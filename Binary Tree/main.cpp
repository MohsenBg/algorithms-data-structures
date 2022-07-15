#include "Tree.cpp"
#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<string> vec);
void PrintLine();
void printVectorNode(vector<shared_ptr<Node>> vec);

int main()
{

	TreeNode A = TreeNode("A",5);
	TreeNode B = TreeNode("B",2);
	TreeNode C = TreeNode("C",5);
	TreeNode D = TreeNode("D",6);
	TreeNode E = TreeNode("E",2);
	
	Tree myTree = Tree(A);		
	myTree.AddBothNode(A.id, B, C);
	myTree.AddLeftNode(C.id, D);
	myTree.AddRightNode(D.id,E);
	

	PrintLine();
	cout << "Find node B (RECURSIVE):" ;
	shared_ptr<Node> NodeB = myTree.FindNodeWithId(B.id,RECURSIVE);
	if(NodeB == nullptr)
		cout << "NULL" << endl;
	else
		NodeB->DebugLog();


	PrintLine();
	cout << "Find node C (DFS):" ;
	shared_ptr<Node> NodeC = myTree.FindNodeWithId(C.id,DFS);
	if(NodeC == nullptr)
		cout << "NULL" << endl;
	else
		NodeC->DebugLog();


	PrintLine();
	cout << "Find node D (BFS):" ;
	shared_ptr<Node> NodeD = myTree.FindNodeWithId(D.id,BFS);
	if(NodeD == nullptr)
		cout << "NULL" << endl;
	else
		NodeD->DebugLog();


	PrintLine();
	cout << "Find node E (MAP):" ;
	shared_ptr<Node> NodeE = myTree.FindNodeWithId(E.id,MAP);
	if(NodeE == nullptr)
		cout << "NULL" << endl;
	else
		NodeE->DebugLog();



	PrintLine();
	int val = 5;
	cout << "Node ID has Value "<< to_string(val) <<": ";
	printVector(myTree.FindNodeWithValue(val));

	PrintLine();
	cout << "Sum node (BFS):" << myTree.SumAllNode(BFS) << endl;
	
	PrintLine();	
	cout << "Sum node (DFS):" << myTree.SumAllNode(DFS) << endl;
	
	PrintLine();	
	cout << "Sum node (RECURSIVE):" << myTree.SumAllNode(RECURSIVE) << endl ;
	
	PrintLine();	
	cout << "Sum node (MAP):" << myTree.SumAllNode(MAP) << endl;
	
	PrintLine();	
	cout << "Node Leafs: " ;
	printVectorNode(myTree.GetLeafs());
	

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

void PrintLine()
{
	cout << "-----------------------\n";
}
void printVectorNode(vector<shared_ptr<Node>> vec)
{
		string show = "[";
		for(shared_ptr<Node> data:vec)
			show += data->GetId() + ",";
		
		if(vec.size() > 0)
			show.pop_back();
		
		show += "]";
		
		cout << show << endl;
}


//Tree Patern
//
//            (A)
//            / \
//           /	 \
//         (B)   (C)
//				 /
//				/
//			  (D)
//				\
//				 \
//				 (E)
