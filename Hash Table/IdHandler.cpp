#ifndef ID_HADNLER
#define ID_HADNLER
#include "Exceptions.cpp"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class IdHandler {
private:
  vector<string> Ids;

public:
  vector<string> GetIds() { return Ids; }

  bool IdExist(string id) {
    for (string Id : Ids)
      if (Id == id)
        return true;
    return false;
  }

  void AddId(string id) {
    if (IdExist(id)) {
      string msg = "id: '" + id + "'" + " used befor please insert unique id";
      CPP_Exception::Error(msg);
      return;
    }
    Ids.push_back(id);
  }

  void RemoveId(string id) {
    int index = -1;
    for (int i = 0; i < Ids.size(); i++)
      if (id == Ids[i])
        index = 1;
    if (index == -1)
      return;
    Ids.erase(Ids.begin() + index);
  }

  void DebugLog() {
    string show = "keys:[";
    for (string id : Ids)
      show += id + ",";
    if (Ids.size() > 0)
      show.pop_back();
    show += "]";
    cout << show << endl;
  }
};

#endif
