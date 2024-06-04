#include <iostream>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    int k[102];
    int s[102];
    int dp[10001] = {0,};

    for(int i = 1; i < n+1; i++){
        cin >> k[i] >> s[i];
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = t; j >= k[i]; j--){
            dp[j] = max(dp[j],dp[j-k[i]]+s[i]);
        }
    }
    cout << dp[t];
}