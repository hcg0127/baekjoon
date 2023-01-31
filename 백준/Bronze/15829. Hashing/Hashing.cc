#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int l,h=0;
  string x;
  cin >> l >> x;
  for (int i=0; i<l; i++) {
    h += (x[i]-96) * (int)pow(31,i);
  }
  cout << h % 1234567891;
}