#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b);
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t,a,b;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> a >> b;
    cout << a * b / gcd(a,b) << '\n';
  }
}