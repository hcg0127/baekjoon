#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

long long int n,m,k,a,b,c,d,dp[101][101]={1};
vector<pair<pii,pii>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({{a,b},{c,d}});
    }

    int tmp=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            a = v[j].first.first, b = v[j].first.second, c = v[j].second.first, d = v[j].second.second;
            if (a==i-1 && b==0 && c==i && d==0 || a==i && b==0 && c==i-1 && d==0) {
                tmp=0;
                break;
            }
        }
        dp[i][0] = tmp;
    }
    tmp=1;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<k; j++) {
            a = v[j].first.first, b = v[j].first.second, c = v[j].second.first, d = v[j].second.second;
            if (a==0 && b==i-1 && c==0 && d==i || a==0 && b==i && c==0 && d==i-1) {
                tmp=0;
                break;
            }
        }
        dp[0][i] = tmp;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            bool x=false, y=false;
            for (int l=0; l<k; l++) {
                a = v[l].first.first, b = v[l].first.second, c = v[l].second.first, d = v[l].second.second;
                if (a==i-1 && b==j && c==i && d==j || a==i && b==j && c==i-1 && d==j) x = true;
                if (a==i && b==j-1 && c==i && d==j || a==i && b==j && c==i && d==j-1) y = true;
            }
            if (!x) dp[i][j] += dp[i-1][j];
            if (!y) dp[i][j] += dp[i][j-1];
        }
    }

    cout << dp[n][m];
}