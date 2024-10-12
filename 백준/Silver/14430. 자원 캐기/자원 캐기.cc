#include <iostream>
using namespace std;

int n,m,mx,dp[301][301];
bool board[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) cin >> board[i][j];
    
    dp[1][1] = (board[1][1]?1:0);
    for (int i=2; i<=n; i++) dp[i][1] = dp[i-1][1]+(board[i][1]?1:0);
    for (int i=2; i<=m; i++) dp[1][i] = dp[1][i-1]+(board[1][i]?1:0);

    for (int i=2; i<=n; i++)
        for (int j=2; j<=m; j++)
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+(board[i][j]?1:0);

    cout << dp[n][m];
}