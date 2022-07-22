#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <memory>
using namespace std;

template <typename T>

class Node {

private:
  shared_ptr<Node<T>> next;

public:
  T value;
  Node(int Value) { value = Value; }

  void setNext(shared_ptr<Node<T>> node) { next = node; }

  shared_ptr<Node<T>> Next() {

    if (next == nullptr)
      return nullptr;

    return next;
  }
};

#endif
