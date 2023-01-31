#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int l;
  long long h=0, r=1;
  string x;
  cin >> l >> x;
  for (int i=0; i<l; i++) {
    h += (x[i]-96) * r % 1234567891;
    r = (r * 31) % 1234567891;
  }
  cout << h;
}