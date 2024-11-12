#include <iostream>
using namespace std;

int n,t,dp[2][1001],d,m,sum;
bool tog;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i=1; i<=n; i++) {
        cin >> d >> m;
        sum += m;
        tog = (i%2==0 ? 0 : 1);
        for (int j=1; j<=t; j++)
            if (j-d>=0) dp[tog][j] = max(dp[!tog][j-d]+m,dp[!tog][j]);
            else dp[tog][j] = dp[!tog][j];
    }
    cout << sum - dp[tog][t];
}