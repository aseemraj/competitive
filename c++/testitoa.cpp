/* itoa example */
#include <bits/stdc++.h>
using namespace std;
int main ()
{
  stringstream ss;
  int x = 23;
  ss << x;
  string str = ss.str();
  cout<<str;
  return 0;
}
