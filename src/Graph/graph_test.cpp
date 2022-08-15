#include "Graph.cpp"
#include "Search.cpp"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printPath(vector<string> path);
string char_to_string(char *c);
void generate_graph_path(Graph &graph);
void string_to_upper(string &str);

int main(int args, char *argv[]) {
  if (args < 3)
    return 0;

  string start = char_to_string(argv[1]);
  string end = char_to_string(argv[2]);
  string flag = char_to_string(argv[3]);
  string_to_upper(flag);

  Graph myGraph;
  generate_graph_path(myGraph);

  // myGraph.DebugLog();
  vector<string> path;

  if (flag == "--BFS") {
    auto path = Search::BFS(myGraph.GetNode(start), myGraph.GetNode(end));
    printPath(path);
  } else if (flag == "--DFS") {
    path = Search::DFS(myGraph.GetNode(start), myGraph.GetNode(end));
    printPath(path);
  } else if (flag == "--A*" || flag == "--ASTAR") {
    path = Search::AStar(myGraph.GetNode(start), myGraph.GetNode(end));
    printPath(path);
  }
  return 0;
}

string char_to_string(char *c) {
  string str = "";
  int len = strlen(c);
  for (int i = 0; i < len; i++) {
    str.push_back(c[i]);
  }
  return str;
}

void generate_graph_path(Graph &graph) {
  NodeData A = NodeData("A", Coord(0, 0));
  NodeData B = NodeData("B", Coord(0, 2));
  NodeData C = NodeData("C", Coord(2, 0));
  NodeData D = NodeData("D", Coord(4, 2));
  NodeData E = NodeData("E", Coord(4, 0));
  NodeData F = NodeData("F", Coord(6, 2));
  NodeData G = NodeData("G", Coord(8, 1));
  NodeData L = NodeData("L", Coord(0, 1));
  NodeData K = NodeData("K", Coord(1, 1));

  graph.AddEage(A, C, DOUBLE);
  graph.AddEage(A, L, DOUBLE);
  graph.AddEage(L, K, DOUBLE);
  graph.AddEage(L, B, DOUBLE);
  graph.AddEage(B, D, DOUBLE);
  graph.AddEage(C, K, DOUBLE);
  graph.AddEage(C, E, DOUBLE);
  graph.AddEage(K, D, DOUBLE);
  graph.AddEage(K, G, DOUBLE);
  graph.AddEage(D, F, DOUBLE);
  graph.AddEage(E, F, DOUBLE);
  graph.AddEage(E, G, DOUBLE);
  graph.AddEage(F, G, DOUBLE);
}
void string_to_upper(string &str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toupper(str[i]);
  }
}
void printPath(vector<string> path) {
  string show = "";
  for (string data : path)
    show += data + " ";

  cout << show << endl;
}

/*
 *		 (A) ====== (C) ====== (E) \
 *		  |          |          |   \
 *		  |          |          |    \
 *		 (L) ====== (K) ============ (G)
 *	    |	         |          |    /
 *	    |          |          |   /
 *		 (B) ====== (D) ====== (F) /
 */
