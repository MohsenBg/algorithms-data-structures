#include "LinkList.cpp"
#include <cstring>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string char_to_string(char *);
void string_to_upper(string &);
void print_vec(vector<int>);

int main(int argc, char *argv[]) {

  // len - file name
  int arr_len = argc - 1;
  LinkList<int> my_linklist;
  string flag;
  vector<int> arg_numbers;
  bool does_pass_flag = false;

  for (int i = 0; i < arr_len; i++) {
    string str = char_to_string(argv[i + 1]);
    if (str.find("--") != string::npos) {
      flag = str;
      string_to_upper(flag);
      does_pass_flag = true;
      continue;
    }

    if (!does_pass_flag) {
      my_linklist.AddElement(stoi(str));
    } else
      arg_numbers.push_back(stoi(str));
  }

  // GetValues
  if (flag == "--GV") {
    print_vec(my_linklist.GetValues());
  }

  // begin
  else if (flag == "--B") {
    cout << my_linklist.begin()->value << " \n";
  }

  // end
  else if (flag == "--E") {
    cout << my_linklist.end()->value << " \n";
  }

  // Count
  else if (flag == "--CO") {
    cout << my_linklist.Count() << " \n";
  }

  // Reverce
  else if (flag == "--RV") {
    my_linklist.Reverce();
    print_vec(my_linklist.GetValues());
  }

  // AtIndex
  else if (flag == "--AI") {
    for (int num : arg_numbers) {
      cout << my_linklist.AtIndex(num)->value << " ";
    }
    cout << endl;
  }

  // Find
  else if (flag == "--F") {
    for (int num : arg_numbers) {
      cout << my_linklist.Find(num) << " ";
    }
    cout << " \n";
  }

  // InList
  else if (flag == "--IL") {
    for (int value : arg_numbers) {
      cout << boolalpha << my_linklist.InList(value) << " ";
    }
    cout << " \n";
  }

  // Remove
  else if (flag == "--RM") {
    for (int index : arg_numbers) {
      my_linklist.Remove(index);
    }
    print_vec(my_linklist.GetValues());

  }

  // Insert
  else if (flag == "--IS") {
    int lens = arg_numbers.size() % 2 == 0 ? arg_numbers.size()
                                           : arg_numbers.size() - 1;

    for (int i = 0; i < lens - 1; i += 2) {
      my_linklist.Insert(arg_numbers[i], arg_numbers[i + 1]);
    }

    if (arg_numbers.size() - lens == 1)
      my_linklist.Insert(arg_numbers.back());

    print_vec(my_linklist.GetValues());
  }

  // ChangeValue
  else if (flag == "--CV") {

    int lens = arg_numbers.size() % 2 == 0 ? arg_numbers.size()
                                           : arg_numbers.size() - 1;

    for (int i = 0; i < lens - 1; i += 2) {
      my_linklist.ChangeValue(arg_numbers[i], arg_numbers[i + 1]);
    }

    print_vec(my_linklist.GetValues());
  }
  return 0;
}

string char_to_string(char *c) {
  string str = "";
  int len = strlen(c);
  for (int i = 0; i < len; i++) {
    str.push_back(c[i]);
  }
  return str;
}

void string_to_upper(string &str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toupper(str[i]);
  }
}

void print_vec(vector<int> vec) {
  for (int num : vec) {
    cout << num << " ";
  }
  cout << endl;
}
