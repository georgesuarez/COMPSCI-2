#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>


using namespace std;

int n = 0;
int j = 0;
int i = 0;
int ct = 0;

int compute(const char *s, const char *t, int ss, int tt) {
  if (i > ss || j > tt) {
    return -1;
  } else {
    if (s[i] == t[j]) {
      i++;
      j++;
      ct++;
      if (j == tt) {
        n = i - j;
      }
      compute(s, t, ss, tt);
    }

    else {
      i++;
      compute(s, t, ss, tt);
    }
  }
  if (ct > 0)
    return (n + 1);
  else
    return -1;
}

int main() {
  char *s = "mississippi";
  char *t = "sip";

  string ss = "mississippi";
  string tt = "sip";

  cout << "Starting position of the second string " << t << endl;
  cout << "In the first string " << s
       << " is: " << compute(s, t, strlen(s), strlen(t)) << endl;

  return 0;
}