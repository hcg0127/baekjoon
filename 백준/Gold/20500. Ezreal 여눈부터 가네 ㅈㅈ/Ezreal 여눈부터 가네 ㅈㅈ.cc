#include <iostream>
#define prime 1000000007
using namespace std;
int main(){
    int n;
    int dp[1516];
    cin >> n;
    dp[1] = 0;dp[2] = 1;
    for(int i = 3; i < n+1; i++){
        if(i%2==0) dp[i] = (dp[i-1]*2+1)%prime;
        else dp[i] = (dp[i-1]*2-1)%prime;
    }
    cout << dp[n];
}