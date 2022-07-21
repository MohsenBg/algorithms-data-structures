#include "LinkList.cpp"
#include <iostream>
#include <memory>

template <typename T>

class HashTable {
private:
  int size;
  shared_ptr<T[]> arr;

  unsigned int HashFunction(string key) {
    int g = 31;

    unsigned int hashValue = 0;

    for (int i = 0; i < key.size(); i++)
      hashValue = g * hashValue + key[i];

    return hashValue % size;
  }

public:
  HashTable(int size) { arr = shared_ptr<T[]>(new int[size]); }
};
