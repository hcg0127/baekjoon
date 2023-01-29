#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x, sum_mn=0;
  cin >> n;
  int a[n], b[n];
  for (int i=0; i<n; i++) {
    cin >> x;
    a[i] = x;
  }
  for (int i=0; i<n; i++) {
    cin >> x;
    b[i] = x;
  }
  sort(a, a+n);
  sort(b, b+n, greater<int>());
  for (int i=0; i<n; i++) {
    sum_mn += a[i] * b[i];
  }
  cout << sum_mn;
}