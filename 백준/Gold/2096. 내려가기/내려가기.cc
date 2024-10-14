#include <iostream>
#include <algorithm>
using namespace std;

int n,dp[3][2][2],a,b,c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool tog;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b >> c;
        tog = (i%2==1 ? true : false);
        dp[0][tog][0] = a + max(dp[0][!tog][0],dp[1][!tog][0]);
        dp[1][tog][0] = b + max({dp[0][!tog][0],dp[1][!tog][0],dp[2][!tog][0]});
        dp[2][tog][0] = c + max(dp[1][!tog][0],dp[2][!tog][0]);

        dp[0][tog][1] = a + min(dp[0][!tog][1],dp[1][!tog][1]);
        dp[1][tog][1] = b + min({dp[0][!tog][1],dp[1][!tog][1],dp[2][!tog][1]});
        dp[2][tog][1] = c + min(dp[1][!tog][1],dp[2][!tog][1]);

    }

    cout << max({dp[0][tog][0],dp[1][tog][0],dp[2][tog][0]}) << ' ' << min({dp[0][tog][1],dp[1][tog][1],dp[2][tog][1]});
}