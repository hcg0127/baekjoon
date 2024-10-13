#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,dp[1001][3]={},a,b,c;
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a >> b >> c;
    dp[i][0]=min(dp[i-1][1]+a,dp[i-1][2]+a);
    dp[i][1]=min(dp[i-1][0]+b,dp[i-1][2]+b);
    dp[i][2]=min(dp[i-1][0]+c,dp[i-1][1]+c);
  }
  cout << min({dp[n][0],dp[n][1],dp[n][2]});
}