#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t,n;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    vector<int> rooms(n+1,1);
    for (int i=2; i<=n; i++) {
      int tmp=i,idx=1;
      while (tmp*idx <= n) {
        rooms[tmp*idx]++;
        idx++;
      }
    }
    int cnt=0;
    for (int i=1; i<=n; i++) {
      if (rooms[i] % 2 == 1) cnt++;
    }
    cout << cnt << '\n';
  }
  
}