#include <iostream>
using namespace std;

class CPP_Exception : public std::exception {
public:
  static void Error(string msg, bool EndProgram = true) {
    try {
      throw 42;
    } catch (int code) {
      cout << msg << endl;
      if (EndProgram)
        exit(2);
    }
  }
};
