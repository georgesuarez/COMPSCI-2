/*
        Write a function sort that sorts the elements of a linked list (without
        copying them into a vector).
*/

#include <ctime>
#include <iostream>
#include <list>
#include <random>

using namespace std;

void sort_list(list<int> &numbers) {
  for (list<int>::iterator iter = numbers.begin(); iter != (--numbers.end());
       iter++) {
    int *smallest = &(*iter);

    list<int>::iterator iter2 = iter;

    for (++iter2; iter2 != numbers.end(); ++iter2) {
      if (*smallest > *iter2) {
        smallest = &(*iter2);
      }
    }

    int temp = *iter;
    *iter = *smallest;
    *smallest = temp;
  }
}

int main() {

  srand(time(NULL));

  list<int> numbers;

  for (int i = 0; i < 10; i++) {
    int random = rand() % 25 + 1;
    numbers.push_back(random);
  }

  cout << "Unsorted list: ";
  for (list<int>::iterator iter = numbers.begin(); iter != numbers.end();
       iter++) {
    cout << *iter << " ";
  }

  cout << endl;

  sort_list(numbers);

  cout << "sorted list: ";
  for (list<int>::iterator iter = numbers.begin(); iter != numbers.end();
       iter++) {
    cout << *iter << " ";
  }

  cout << endl;

  return 0;
}