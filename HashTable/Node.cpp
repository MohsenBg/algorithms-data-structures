#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>

class Node {

private:
  T value;
  shared_ptr<Node> next;

public:
  Node(T Value) { value = Value; }
  shared_ptr<Node> GetNext() { return next; }
  T GetValue() { return value; }
  void SetValue(T Value) { value = Value; }
  void SetNext(shared_ptr<Node> Next) { next = Next; }
};

#endif
