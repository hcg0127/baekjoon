#include <iostream>
using namespace std;

int gcd(int a, int b);
int gcd(int a, int b) {
  while (b!=0) {
    int r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,fst;
  cin >> n;
  int ans[n-1];
  for (int i=0; i<n; i++) {
    cin >> ans[i];
  }
  fst = ans[0];
  for (int i=1; i<n; i++) {
    int g = gcd(fst,ans[i]);
    cout << fst/g << '/' << ans[i]/g << '\n';
  }
}