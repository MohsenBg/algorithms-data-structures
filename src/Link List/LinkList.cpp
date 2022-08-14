#ifndef LINK_LIST_CPP
#define LINK_LIST_CPP
#include "Node.cpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

template <typename T>

class LinkList {
private:
  // first Node
  shared_ptr<Node<T>> head;

  // last Node
  shared_ptr<Node<T>> tail;

  // number of Node
  int counter = 0;

public:
  // return number of Node exists in List
  int Count() { return counter; }

  // return fist Node(Head) in List
  shared_ptr<Node<T>> begin() { return head; }

  // return last Node(tail) in List
  shared_ptr<Node<T>> end() { return tail; }

  // Print all Element of List , example => [1,2,3,...]
  void DebugLog() {
    shared_ptr<Node<T>> currentNode = head;
    int c = 0;

    string data = "[";
    // loop all node and get values (start from head)
    while (currentNode != nullptr) {
      data += to_string(currentNode->value) + ",";
      currentNode = currentNode->Next();
      c++;
    }

    if (c > 0)
      data.pop_back();
    data += "]";
    cout << data << endl;
  }

  // Add new Values(Node) end of the List same as Insert with Defult index
  void AddElement(int value) {

    // first Element
    if (counter == 0) {
      head = shared_ptr<Node<T>>(new Node<T>(value));
      tail = head;
      counter += 1;
      return;
    }

    shared_ptr<Node<T>> newNode = shared_ptr<Node<T>>(new Node<T>(value));
    tail->setNext(newNode);
    tail = newNode;
    counter += 1;
  }

  // return vector (similar to array) All value(Not Node) in List
  vector<int> GetValues() {
    vector<int> Values;
    shared_ptr<Node<T>> currentNode = head;

    // loop all node and get values (start from head)
    while (currentNode != nullptr) {
      Values.push_back(currentNode->value);
      currentNode = currentNode->Next();
    }

    return Values;
  }

  // If value exsits in List return index of the value otherwise return -1
  int Find(int value) {
    shared_ptr<Node<T>> currentNode = head;
    int c = 0;
    while (currentNode != nullptr) {
      if (currentNode->value == value)
        return c;
      currentNode = currentNode->Next();
      c++;
    }
    return -1;
  }

  // If value exists in List return true otherwise return false
  bool InList(int value) {
    shared_ptr<Node<T>> currentNode = head;
    while (currentNode != nullptr) {
      if (currentNode->value == value)
        return true;
      currentNode = currentNode->Next();
    }
    return false;
  }

  // Find Node by the index
  shared_ptr<Node<T>> AtIndex(int index) {
    if (index < 0)
      index = counter + index;
    shared_ptr<Node<T>> currentNode = head;
    int c = 0;
    while (c <= index) {
      if (c == index)
        return currentNode;
      currentNode = currentNode->Next();
      c++;
    }
    return nullptr;
  }

  // Change Value of a Node by index
  void ChangeValue(int value, int index) {
    if (index < 0)
      index = counter + index;

    shared_ptr<Node<T>> currentNode;

    if (index == counter - 1)
      currentNode = tail;

    else if (index == 0)
      currentNode = head;

    else
      currentNode = AtIndex(index);

    currentNode->value = value;
  }

  // Insert new Value(Node) in List by index. Defult add end of the list
  void Insert(int value, int index = -1) {

    if (index < 0)
      index = counter + index;

    // count index from last
    if (index == counter - 1) {
      AddElement(value);
      return;
    }

    shared_ptr<Node<T>> newNode = shared_ptr<Node<T>>(new Node<T>(value));

    shared_ptr<Node<T>> currentNode;

    if (index == 0) {
      currentNode = head;
      head = newNode;
      head->setNext(currentNode);
      counter += 1;
      return;
    }
    currentNode = AtIndex(index - 1);
    shared_ptr<Node<T>> nextNode = currentNode->Next();
    currentNode->setNext(newNode);
    newNode->setNext(nextNode);
    counter += 1;
  }

  // Remove A node from List by the index. Defult Remove last Node
  void Remove(int index = -1) {

    if (index < 0)
      index = counter + index;

    // count index from last
    if (index == counter - 1) {
      tail = AtIndex(counter - 2);
      tail->setNext(nullptr);
      counter -= 1;
      return;
    }

    if (index == 0) {
      head = head->Next();
      counter -= 1;
      return;
    }

    shared_ptr<Node<T>> beforNodeCurrent = AtIndex(index - 1);
    shared_ptr<Node<T>> afterNodeCurrent = AtIndex(index + 1);
    beforNodeCurrent->setNext(afterNodeCurrent);
    counter -= 1;
  }

  // Reverce all Node in List
  void Reverce() {
    shared_ptr<Node<T>> currentNode = head;
    shared_ptr<Node<T>> prevNode = nullptr;
    shared_ptr<Node<T>> next = nullptr;
    while (currentNode != nullptr) {
      shared_ptr<Node<T>> next = currentNode->Next();
      currentNode->setNext(prevNode);
      prevNode = currentNode;
      currentNode = next;
    }
    tail = head;
    head = prevNode;
  }
};
#endif
