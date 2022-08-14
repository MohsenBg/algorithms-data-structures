#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct Coord {
  Coord(int X, int Y) {
    x = X;
    y = Y;
  }

  int x;
  int y;
};

class Node {
private:
  vector<shared_ptr<Node>> neighbors;

  bool IsNeighborsExist(shared_ptr<Node> node) {
    for (shared_ptr<Node> neighbor : neighbors)
      if (neighbor->name == node->name)
        return true;
    return false;
  }
  Coord postion = Coord(0, 0);

public:
  string name;

  float Calcdistance(shared_ptr<Node> node) {
    float x = node->GetPostion().x - postion.x;
    float y = node->GetPostion().y - postion.y;
    return sqrt(pow(x, 2) + pow(y, 2));
  }

  Node(string Name, Coord Postion = Coord(0, 0)) {
    postion = Postion;
    name = Name;
  }

  void setPostion(Coord Postion) { postion = Postion; }

  Coord GetPostion() { return postion; }
  void AddNeighbors(shared_ptr<Node> node) {
    if (!IsNeighborsExist(node))
      neighbors.push_back(node);
  }

  vector<shared_ptr<Node>> GetNeighbor() { return neighbors; }

  void DebugLog() {

    string show = "[" + name + "]: {";

    for (shared_ptr<Node> neighbor : neighbors)
      show += neighbor->name + ",";

    if (neighbors.size() > 0)
      show.pop_back();

    show += "}";

    cout << show << endl;
  }
};

#endif
