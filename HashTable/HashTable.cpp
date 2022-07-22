#include "LinkList.cpp"
#include <iostream>
#include <memory>
#include <vector>

template <typename T>

class HashTable {
private:
  int size;
  shared_ptr<LinkList<T>> *storage;
  vector<string> keys;

  unsigned int HashFunction(string key) {
    int g = 31;

    unsigned int hashValue = 0;

    for (int i = 0; i < key.size(); i++)
      hashValue = g * hashValue + key[i];

    return hashValue % size;
  }

public:
  HashTable(int Size) {
    size = Size;
    storage = new shared_ptr<LinkList<T>>[Size];
  }

  void AddItem(string key, T value) {
    unsigned int index = HashFunction(key);

    if (storage[index] == nullptr) {
      shared_ptr<LinkList<T>> newLinkList =
          shared_ptr<LinkList<T>>(new LinkList<T>());
      storage[index] = newLinkList;
    }
    storage[index]->AddNode(key, value);
    keys.push_back(key);
  }

  void ChangeValue(string key, T newValue) {
    unsigned int index = HashFunction(key);
    string msg = "you can not change value of node wiht key: '" + key + "' " +
                 "Beacuse not exist";

    if (storage[index] == nullptr) {
      CPP_Exception::Error(msg);
      return;
    }

    shared_ptr<Node<T>> node = storage[index]->FindNodeWithId(key);
    if (node == nullptr) {
      CPP_Exception::Error(msg);
      return;
    }
    node->SetValue(newValue);
  }

  bool IsKeyExist(string key) {
    unsigned int index = HashFunction(key);
    if (storage[index] == nullptr)
      return false;
    shared_ptr<Node<T>> node = storage[index]->FindNodeWithId(key);
    if (node == nullptr)
      return false;
    return true;
  }
  vector<string> GetKeys() { return keys; }
  shared_ptr<LinkList<T>> GetLinkList(string key) {
    unsigned int index = HashFunction(key);
    return storage[index];
  }
  shared_ptr<Node<T>> GetNode(string key) {
    if (GetLinkList(key) == nullptr)
      return nullptr;
    shared_ptr<Node<T>> node = GetLinkList(key)->FindNodeWithId(key);
    return node;
  }
};
