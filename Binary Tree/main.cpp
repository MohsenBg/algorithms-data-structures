#include "Tree.cpp"
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> vec);

void PrintLine();

template <typename T> void printVectorNode(vector<shared_ptr<Node<T>>> vec);

int main() {

  TreeNode<int> A = TreeNode<int>("A", 5);
  TreeNode<int> B = TreeNode<int>("B", 2);
  TreeNode<int> C = TreeNode<int>("C", 5);
  TreeNode<int> D = TreeNode<int>("D", 6);
  TreeNode<int> E = TreeNode<int>("E", 2);

  Tree<int> myTree = Tree<int>(A);
  myTree.AddBothNode(A.id, B, C);
  myTree.AddLeftNode(C.id, D);
  myTree.AddRightNode(D.id, E);

  PrintLine();
  cout << "Find node B (RECURSIVE):";
  shared_ptr<Node<int>> NodeB = myTree.FindNodeWithId(B.id, RECURSIVE);
  if (NodeB == nullptr)
    cout << "NULL" << endl;
  else
    NodeB->DebugLog();

  PrintLine();
  cout << "Find node C (DFS):";
  shared_ptr<Node<int>> NodeC = myTree.FindNodeWithId(C.id, DFS);
  if (NodeC == nullptr)
    cout << "NULL" << endl;
  else
    NodeC->DebugLog();

  PrintLine();
  cout << "Find node D (BFS):";
  shared_ptr<Node<int>> NodeD = myTree.FindNodeWithId(D.id, BFS);
  if (NodeD == nullptr)
    cout << "NULL" << endl;
  else
    NodeD->DebugLog();

  PrintLine();
  cout << "Find node E (MAP):";
  shared_ptr<Node<int>> NodeE = myTree.FindNodeWithId(E.id, MAP);
  if (NodeE == nullptr)
    cout << "NULL" << endl;
  else
    NodeE->DebugLog();

  PrintLine();
  int val = 5;
  cout << "Node ID has Value " << to_string(val) << ": ";
  printVector(myTree.FindNodeWithValue(val));

  PrintLine();
  cout << "Sum node (BFS):" << myTree.SumAllNode(BFS) << endl;

  PrintLine();
  cout << "Sum node (DFS):" << myTree.SumAllNode(DFS) << endl;

  PrintLine();
  cout << "Sum node (RECURSIVE):" << myTree.SumAllNode(RECURSIVE) << endl;

  PrintLine();
  cout << "Sum node (MAP):" << myTree.SumAllNode(MAP) << endl;

  PrintLine();
  cout << "Node Leafs: ";
  printVectorNode(myTree.GetLeafs());

  return 0;
}

void printVector(vector<string> vec) {
  string show = "[";
  for (string data : vec)
    show += data + ",";

  if (vec.size() > 0)
    show.pop_back();

  show += "]";

  cout << show << endl;
}

void PrintLine() { cout << "-----------------------\n"; }

template <typename T> void printVectorNode(vector<shared_ptr<Node<T>>> vec) {
  string show = "[";
  for (shared_ptr<Node<T>> data : vec)
    show += data->GetId() + ",";

  if (vec.size() > 0)
    show.pop_back();

  show += "]";

  cout << show << endl;
}

// Tree Patern
//
//            (A)
//            / \
//           /	 \
//         (B)   (C)
//               /
//              /
//            (D)
//              \
//               \
//               (E)
