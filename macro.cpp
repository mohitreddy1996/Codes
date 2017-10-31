#include "bits/stdc++.h"

using namespace std;

#define test1(a, b, c) \
  cout << a << endl; \
  cout << b << endl; \
  cout << "Inside macro" << endl;

#define test(a, b) test1(a, b, c)

int aa (int a) {
  cout << "Inside function: " << a << endl;
  return 0;
}

int main () {
  int a = 9;
  test(a, aa(a)) test1(a, aa(a), a)
  return 0;
}
