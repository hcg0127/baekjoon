#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    int n,m;
    cin >> n >> m;

    long long ans = 1;

    int r=1;
    for (int i=m; i>m-n; i--) {
      ans *= i;
      ans /= r++;
    }
    cout << ans << '\n';
  }
}