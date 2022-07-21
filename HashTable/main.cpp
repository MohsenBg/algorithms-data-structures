#include "LinkList.cpp"
#include <iostream>
#include <memory>

int main() {
  LinkList<int> mylinkList;
  mylinkList.AddNode(5);
  mylinkList.Insert(2, 0);
  return 0;
}
