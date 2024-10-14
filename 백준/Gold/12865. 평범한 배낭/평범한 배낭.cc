#include <iostream>
using namespace std;

int n,k,w,v,dp[2][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    bool tog;
    for (int i=1; i<=n; i++) {
        cin >> w >> v;
        tog = (i%2==1 ? 1 : 0);
        for (int j=1; j<=k; j++) {
            if (j>=w) dp[tog][j] = max(dp[!tog][j],dp[!tog][j-w]+v);
            else dp[tog][j] = dp[!tog][j];
        }
    }
    cout << dp[tog][k];
}