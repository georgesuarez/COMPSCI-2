#include "complex.h"
#include <iostream>

using namespace std;

int main() {

  Complex a, b, c, d(-5), e(1, -2);

  cout << "Read b: ";
  cin >> b;

  cout << "Read c: ";
  cin >> c;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl << endl;

  cout << "b + c = " << b + c << endl;
  cout << "b - c = " << b - c << endl;
  cout << "b * c = " << b * c << endl;
  cout << "b / c = " << b / c << endl << endl;

  b += c;

  cout << b << endl;

  b -= c;
  cout << b << endl;

  b *= c;
  cout << b << endl;

  b /= c;
  cout << b << endl << endl;

  return 0;
}