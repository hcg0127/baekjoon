#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t,n,m,x;
  cin >> t;
  for (int i=0; i<t; i++) {
    queue<pair<int,int>> rank;
    int nums[9]= {0,};
    int cnt=0;
    cin >> n >> m;
    for (int j=0; j<n; j++) {
      cin >> x;
      nums[x-1]++;
      rank.push({x,j});
    }
    int mx = 9;
    bool flag = true;
    while (flag && mx>0) {
      if (nums[mx-1] == 0) mx--;
      else {
        while (nums[mx-1] != 0) {
          if (rank.front().first < mx) {
            rank.push(rank.front());
            rank.pop();
          }
          else {
            cnt++;
            if (rank.front().second == m) {
              cout << cnt << '\n';
              flag = false;
              break;
            }
            rank.pop();
            nums[mx-1]--;
          }
        }
        mx--;
      }
    }
  }
}