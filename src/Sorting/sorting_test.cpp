#include "Sorting.cpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

string char_to_string(char a[], int size);
int *copy_array(int *arr, int size);

int main(int argc, char *argv[]) {

  int len = argc - 2;
  if (len < 1)
    exit(0);
  int my_arr[len + 1];

  char flag;
  flag = argv[len + 1][2];

  for (int i = 1; i < len + 1; i++) {
    int size = strlen(argv[i]);
    string str = char_to_string(argv[i], size);
    my_arr[i - 1] = stoi(str);
  }

  int *my_copy_arr;
  my_copy_arr = copy_array(my_arr, len);
  switch (tolower(flag)) {

    // BubbleSort
  case 'b':
    Sorting::BubbleSort(my_copy_arr, len);
    break;

    // InsertionSort
  case 'i':
    Sorting::InsertionSort(my_copy_arr, len);
    break;

    // SelectionSort
  case 's':
    Sorting::SelectionSort(my_copy_arr, len);
    break;

    // QuickSort
  case 'q':
    Sorting::QuickSort(my_copy_arr, len - 1);
    break;

    // MargeSort
  case 'm':
    Sorting::MargeSort(my_copy_arr, len);
    break;

  default:
    return 0;
  }

  for (int i = 0; i < len; i++) {
    cout << my_copy_arr[i] << " ";
  }
  cout << "\n";
  delete my_copy_arr;

  return 0;
}

string char_to_string(char *a, int size) {
  int i;
  string s = "";
  for (i = 0; i < size; i++) {
    s += a[i];
  }
  return s;
}

int *copy_array(int *arr, int size) {
  int *new_arr = new int[size];
  for (int i = 0; i < size; i++) {
    new_arr[i] = arr[i];
  }
  return new_arr;
}
