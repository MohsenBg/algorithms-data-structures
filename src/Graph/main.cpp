#include "Graph.cpp"
#include "Search.cpp"
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> vec);
void printPath(vector<string> path);
int main() {
  Graph myGraph;

  NodeData A = NodeData("A", Coord(1, 1));
  NodeData B = NodeData("B", Coord(1, 2));
  NodeData C = NodeData("C", Coord(1, 3));
  NodeData D = NodeData("D", Coord(1, 4));
  NodeData E = NodeData("E", Coord(1, 5));
  NodeData F = NodeData("F", Coord(2, 1));
  NodeData G = NodeData("G", Coord(2, 2));
  NodeData H = NodeData("H", Coord(2, 3));
  NodeData I = NodeData("I", Coord(2, 4));
  NodeData J = NodeData("J", Coord(2, 5));
  NodeData K = NodeData("K", Coord(3, 1));
  NodeData L = NodeData("L", Coord(3, 2));
  NodeData M = NodeData("M", Coord(3, 3));
  NodeData N = NodeData("N", Coord(3, 4));
  NodeData P = NodeData("P", Coord(3, 5));
  NodeData Q = NodeData("Q", Coord(4, 1));
  NodeData R = NodeData("R", Coord(4, 2));
  NodeData S = NodeData("S", Coord(4, 3));
  NodeData T = NodeData("T", Coord(4, 4));
  NodeData U = NodeData("U", Coord(4, 5));
  NodeData V = NodeData("V", Coord(5, 1));
  NodeData W = NodeData("W", Coord(5, 2));
  NodeData X = NodeData("X", Coord(5, 3));
  NodeData Y = NodeData("Y", Coord(5, 4));
  NodeData Z = NodeData("Z", Coord(5, 5));

  myGraph.AddEage(A, B, DOUBLE);
  myGraph.AddEage(A, F, DOUBLE);
  myGraph.AddEage(B, C, DOUBLE);
  myGraph.AddEage(B, G, DOUBLE);
  myGraph.AddEage(C, D, DOUBLE);
  myGraph.AddEage(C, H, DOUBLE);
  myGraph.AddEage(D, E, DOUBLE);
  myGraph.AddEage(D, I, DOUBLE);
  myGraph.AddEage(E, J, DOUBLE);
  myGraph.AddEage(F, G, DOUBLE);
  myGraph.AddEage(F, K, DOUBLE);
  myGraph.AddEage(G, H, DOUBLE);
  myGraph.AddEage(G, L, DOUBLE);
  myGraph.AddEage(H, I, DOUBLE);
  myGraph.AddEage(H, M, DOUBLE);
  myGraph.AddEage(I, J, DOUBLE);
  myGraph.AddEage(I, N, DOUBLE);
  myGraph.AddEage(J, P, DOUBLE);
  myGraph.AddEage(K, L, DOUBLE);
  myGraph.AddEage(K, Q, DOUBLE);
  myGraph.AddEage(L, M, DOUBLE);
  myGraph.AddEage(L, R, DOUBLE);
  myGraph.AddEage(M, N, DOUBLE);
  myGraph.AddEage(M, S, DOUBLE);
  myGraph.AddEage(N, P, DOUBLE);
  myGraph.AddEage(N, T, DOUBLE);
  myGraph.AddEage(P, U, DOUBLE);
  myGraph.AddEage(Q, R, DOUBLE);
  myGraph.AddEage(Q, V, DOUBLE);
  myGraph.AddEage(R, S, DOUBLE);
  myGraph.AddEage(R, W, DOUBLE);
  myGraph.AddEage(S, T, DOUBLE);
  myGraph.AddEage(S, X, DOUBLE);
  myGraph.AddEage(T, Y, DOUBLE);
  myGraph.AddEage(T, U, DOUBLE);
  myGraph.AddEage(U, Z, DOUBLE);
  myGraph.AddEage(V, W, DOUBLE);
  myGraph.AddEage(W, X, DOUBLE);
  myGraph.AddEage(X, Y, DOUBLE);
  myGraph.AddEage(Y, Z, DOUBLE);

  myGraph.DebugLog();

  cout << "----------------------------\n";
  cout << "Breadth Fist Search \n";
  vector<string> path = Search::BFS(myGraph.GetNode("A"), myGraph.GetNode("Z"));
  printPath(path);

  cout << "----------------------------\n";
  cout << "Depth Fist Search \n";
  path = Search::DFS(myGraph.GetNode("A"), myGraph.GetNode("Z"));
  printPath(path);

  cout << "----------------------------\n";
  cout << "AStar \n";
  path = Search::AStar(myGraph.GetNode("A"), myGraph.GetNode("Z"));
  printPath(path);

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

void printPath(vector<string> path) {
  string show = "";
  for (string data : path)
    show += data + " -> ";

  if (path.size() > 1) {
    for (int i = 0; i < 4; i++) {
      show.pop_back();
    }
  }
  cout << show << endl;
}

/*
       (A)----(B)----(C)----(D)----(E)
        |      |      |      |      |
       (F)----(G)----(H)----(I)----(J)
        |      |      |      |      |
       (K)----(L)----(M)----(N)----(P)
        |      |      |      |      |
       (Q)----(R)----(S)----(T)----(U)
        |      |      |      |      |
       (V)----(W)----(X)----(Y)----(Z)
 */
