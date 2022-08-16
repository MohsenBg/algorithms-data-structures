#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <memory>
#include <string>
#include <vector>

    using namespace std;

class ID {
private:
  char charecters[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0',
                         '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  vector<string> ides;

  bool IsIdExit(string id) {
    for (string exitsId : ides)
      if (exitsId == id)
        return true;
    return false;
  }

public:
  string GenrateId(string name) {
    if (name != "" && !IsIdExit(name)) {
      ides.push_back(name);
      return name;
    }
    string id;
    do {
      id = "";
      for (int i = 0; i < 10; i++) {
        int index = (rand() % 35);
        id.push_back(charecters[index]);
      }
    } while (IsIdExit(id));

    ides.push_back(id);
    return id;
  }
};

ID ID_Contorller = ID();

template <typename T>

class Node : public enable_shared_from_this<Node<T>> {
private:
  string id;
  T value;

  shared_ptr<Node<T>> parnet;
  shared_ptr<Node<T>> right;
  shared_ptr<Node<T>> left;

public:
  Node(string name, T Value) {
    value = Value;
    id = ID_Contorller.GenrateId(name);
  }

  struct BothChild {
    BothChild(shared_ptr<Node<T>> Right, shared_ptr<Node<T>> Left) {
      right = Right;
      left = Left;
    }
    shared_ptr<Node<T>> right;
    shared_ptr<Node<T>> left;
  };

  string GetId() { return id; }

  T GetValue() { return value; }

  shared_ptr<Node<T>> GetParent() { return parnet; }

  shared_ptr<Node<T>> GetLeftNode() { return left; }

  shared_ptr<Node<T>> GetRightNode() { return right; }

  BothChild GetBothChild() { return BothChild(right, left); }

  void SetParent(shared_ptr<Node<T>> Parnet) { parnet = Parnet; }

  void SetRightNode(shared_ptr<Node<T>> node) {
    right = node;
    right->SetParent(this->shared_from_this());
  }

  void SetLeftNode(shared_ptr<Node<T>> node) {
    left = node;
    left->SetParent(this->shared_from_this());
  }

  void ChangeValue(T Value) { value = Value; }

  void DebugLog() {
    string show = "{\n";
    show += "   id:" + id + "\n";
    show += "   value:" + to_string(value) + "\n";
    if (right == nullptr)
      show += "   right: nullptr \n";
    else {
      show += "   right:{ \n";
      show += "      id:" + right->id + "\n";
      show += "      value:" + to_string(right->value) + "\n";
      show += "   }\n";
    }

    if (left == nullptr)
      show += "   left: nullptr \n";
    else {
      show += "   left:{\n";
      show += "      id:" + left->id + "\n";
      show += "      value:" + to_string(left->value) + "\n";
      show += "   }\n";
    }
    show += "}\n";
    cout << show;
  }
};

#endif
