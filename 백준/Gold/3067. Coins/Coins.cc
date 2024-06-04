#include <iostream>
#include <cstring>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,n,m;
    int coin[21];
    ll dp[10001] = {0,};
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1 ; i < n+1; i++){
            cin >> coin[i];
        }
        cin >> m;
        dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            for(int j = coin[i]; j < m+1; j++){
                dp[j] = dp[j] + dp[j-coin[i]];
            }
        }
        cout << dp[m] << endl;
        memset(dp,0,sizeof(dp));
    }
}