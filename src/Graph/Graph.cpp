#ifndef GRAP_CPP
#define GRAP_CPP

#include "Node.cpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;

enum PATH { SINGEL, DOUBLE };

struct NodeData {
  NodeData(string Name, Coord Postion = Coord(0, 0)) {
    name = Name;
    postion = Postion;
  }
  string name;
  Coord postion = Coord(0, 0);
};

class Graph {
private:
  map<string, shared_ptr<Node>> nodes;

  shared_ptr<Node> FindNode(NodeData node) {
    if (nodes.count(node.name) > 0)
      return nodes[node.name];

    nodes[node.name] = shared_ptr<Node>(new Node(node.name, node.postion));
    return nodes[node.name];
  }

public:
  void AddEage(NodeData from, NodeData to, PATH path = SINGEL) {
    shared_ptr<Node> From = FindNode(from);
    shared_ptr<Node> To = FindNode(to);
    From->AddNeighbors(To);
    if (path == DOUBLE)
      To->AddNeighbors(From);
  }

  void DebugLog() {

    for (auto it = nodes.begin(); it != nodes.end(); it++)
      it->second->DebugLog();
  }

  shared_ptr<Node> GetNode(string name) { return nodes[name]; }
};

#endif
