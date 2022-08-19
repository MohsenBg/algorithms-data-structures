#include "HashTable.cpp"
#include <cstring>
#include <iostream>
#include <vector>

struct Flage_Data {
  Flage_Data(string flag, vector<string> args_flag) {
    this->flag = flag;
    this->args_flag = args_flag;
  };
  string flag;
  vector<string> args_flag;
};

struct Map {
  Map(string key, string value) {
    this->value = value;
    this->key = key;
  }
  string key;
  string value;
};

vector<Map> get_hastable_inputs(int size, char **);
string char_to_str(char *);
Flage_Data get_flag_data(int size, char **argv, int start);
string str_to_upper(string str);
void print_hash_table(HashTable<string>);

template <typename T> void print_vec(vector<T>);

int main(int argc, char *argv[]) {

  int hash_table_size = argc - 1;

  if (hash_table_size < 1)
    return 0;

  vector<Map> inputs = get_hastable_inputs(hash_table_size - 1, argv);

  Flage_Data flag_data =
      get_flag_data(hash_table_size, argv, inputs.size() - 2);

  HashTable<string> hash_table = HashTable<string>(hash_table_size * 1.2);
  for (Map map : inputs) {
    hash_table.AddItem(map.key, map.value);
  }

  string &flag = flag_data.flag;

  // GetKeys
  if (flag == "--GK") {
    print_vec(hash_table.GetKeys());
  }

  // IsKeyExist
  else if (flag == "--IKE") {
    for (string key : flag_data.args_flag) {
      cout << hash_table.IsKeyExist(key) << " ";
    }
    cout << endl;
  }

  // GetNode
  else if (flag == "--GN") {
    for (string key : flag_data.args_flag) {
      if (hash_table.GetNode(key) == nullptr)

        continue;
      cout << hash_table.GetNode(key)->GetValue() << " ";
    }
    cout << endl;
  }

  // ChangeValue
  else if (flag == "--CV") {
    int len = flag_data.args_flag.size();
    if (len % 2 == 1)
      len -= 1;

    for (int i = 0; i < len; i += 2) {
      vector<string> &args = flag_data.args_flag;
      if (hash_table.GetNode(args[i]) == nullptr)
        continue;

      hash_table.ChangeValue(args[i], args[i + 1]);
    }
    print_hash_table(hash_table);
  }

  // GetValue
  else if (flag == "--GV") {
    print_hash_table(hash_table);
  }
  return 0;
}

vector<Map> get_hastable_inputs(int size, char **argv) {
  vector<Map> vec;
  for (int i = 0; i < size; i += 2) {
    string str1 = char_to_str(argv[i + 1]);
    string str2 = char_to_str(argv[i + 2]);

    if (str1.find("--") != string::npos || str2.find("--") != string::npos)
      break;

    vec.push_back(Map(str1, str2));
  }
  return vec;
}

Flage_Data get_flag_data(int size, char **argv, int start = 0) {
  string flag = "";
  vector<string> args;

  bool is_flag_pass = false;
  for (int i = start; i < size; i++) {
    string str = char_to_str(argv[i + 1]);
    if (str.find("--") != string::npos) {
      is_flag_pass = true;
      flag = str_to_upper(str);
      continue;
    }
    if (is_flag_pass) {
      args.push_back(str);
    }
  }

  return Flage_Data(flag, args);
}

string str_to_upper(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

string char_to_str(char *c) {
  int len = strlen(c);
  string str = "";
  for (int i = 0; i < len; i++) {
    str.push_back(c[i]);
  }
  return str;
}

void print_hash_table(HashTable<string> h_t) {
  vector<string> keys = h_t.GetKeys();
  for (string key : keys) {
    if (h_t.GetNode(key) == nullptr)
      continue;
    cout << h_t.GetNode(key)->GetValue() << " ";
  }
  cout << endl;
}

template <typename T> void print_vec(vector<T> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
