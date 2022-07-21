#ifndef LINK_LIST_CPP
#define LINK_LIST_CPP
#include "Node.cpp"
#include <iostream>
#include <memory>

template <typename T> class LinkList {
private:
  shared_ptr<Node<T>> head;
  shared_ptr<Node<T>> tail;
  int count = 0;

public:
  void AddNode(T value) {
    if (tail == nullptr) {
      shared_ptr<Node<T>> node = shared_ptr<Node<T>>(new Node<T>(value));
      head = node;
      tail = node;
    } else {
      shared_ptr<Node<T>> node = shared_ptr<Node<T>>(new Node<T>(value));
      tail->SetNext(node);
      tail = node;
    }
    count++;
  }

  shared_ptr<Node<T>> FindNodeWithIndex(int index) {
    shared_ptr<Node<T>> currentNode = head;
    int counter = 0;
    while (currentNode != nullptr) {
      if (counter == index)
        return currentNode;
      counter += 1;
      currentNode = currentNode->GetNext();
    }
    return nullptr;
  }

  shared_ptr<Node<T>> FindNodeWithValue(T value) {
    shared_ptr<Node<T>> currentNode = head;
    while (currentNode != nullptr) {
      if (currentNode->GetValue() == value)
        return currentNode;
      currentNode = currentNode->GetNext();
    }
    return nullptr;
  }

  void Insert(T value, int index = -1) {

    if (index < 0)
      index = count - index;

    if (index == count - 1) {
      AddNode(value);
      return;
    }

    else if (index == 0) {
      shared_ptr<Node<T>> newNode = shared_ptr<Node<T>>(new Node<T>(value));
      newNode->SetNext(head);
      head = newNode;
    }

    else {
      shared_ptr<Node<T>> currentNode = FindNodeWithIndex(index);
      shared_ptr<Node<T>> parentNode = FindNodeWithIndex(index - 1);

      if (parentNode == nullptr || currentNode == nullptr)
        return;

      shared_ptr<Node<T>> node = shared_ptr<Node<T>>(new Node<T>(value));
      parentNode->SetNext(node);
      node->SetNext(currentNode);
    }

    count++;
  }

  void DeleteWithIndex(int index = -1) {

    shared_ptr<Node<T>> currentNode = FindNodeWithIndex(index);
    shared_ptr<Node<T>> parentNode = FindNodeWithIndex(index - 1);

    if (currentNode == nullptr)
      return;

    if (index < 0)
      index = count - index;

    if (index == count - 1) {
      parentNode->SetNext(nullptr);
    }

    else if (index == 0) {
      head = head->SetNext();
    } else {
      parentNode->SetNext(currentNode->GetNext());
    }
    count--;
  }

  int GetCount() { return count; }
  shared_ptr<Node<T>> GetTail() { return tail; }
  shared_ptr<Node<T>> GetHead() { return head; }
};

#endif
