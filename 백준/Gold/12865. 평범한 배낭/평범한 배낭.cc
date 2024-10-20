#include <iostream>
using namespace std;

int n,k,w,v,dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> w >> v;
        for (int j=k; j>=w; j--) dp[j] = max(dp[j],dp[j-w]+v);
    }
    cout << dp[k];
}