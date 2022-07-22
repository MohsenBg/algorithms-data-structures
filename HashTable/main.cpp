#include "HashTable.cpp"
#include "Numbers.cpp"
#include <iostream>
#include <memory>
int main() {
  srand(time(NULL));
  const int size = numbers.size();
  HashTable<int> myHashTable(size * 1.3);

  for (int i = 0; i < numbers.size(); i++) {
    int index = random() % numbers.size();
    myHashTable.AddItem(to_string(numbers[index]), numbers[index]);
    numbers.erase(numbers.begin() + index);
  }

  vector<string> keys = myHashTable.GetKeys();
  int I = random() % keys.size() - 1;

  cout << "myHashTable[" << keys[I]
       << "]: " << myHashTable.GetNode(keys[I])->GetValue() << endl;
  return 0;
}
