#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, cnt = 0;
  cin >> n;
  if (n == 3 || n == 6 || n == 9 || n == 12) {
    cout << n/3;
    return 0;
  }
  else if (n == 4 || n == 7) {
    cout << -1;
    return 0;
  }
  else {
    int mod = n % 5;
    int mok = n / 5;
    while (mod <= n) {
      if (mod % 3 == 0) {
        cout << mok + mod / 3;
        return 0;
      }
      else {
        mok--;
        mod += 5;
      }
    }
    cout << -1;
    return 0;
  }
}