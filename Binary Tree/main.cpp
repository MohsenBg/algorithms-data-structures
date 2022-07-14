#include "Tree.cpp"
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> vec);

int main()
{

	TreeNode A = TreeNode("A",5);
	TreeNode B = TreeNode("B",3);
	TreeNode C = TreeNode("C",5);
	TreeNode D = TreeNode("D",4);
	TreeNode E = TreeNode("E",2);
	
	Tree myTree = Tree(A);		
	myTree.AddBothNode(A.id, B, C);
	myTree.AddLeftNode(C.id, D);
	myTree.AddRightNode(D.id,E);
	
	shared_ptr<Node> nodeC = myTree.FindNodeWithId(C.id);
	nodeC->DebugLog();
	printVector(myTree.FindNodeWithValue(5));
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
