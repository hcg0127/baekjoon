#include <iostream>
#include <algorithm>
using namespace std;

int n,k,ans;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> str;
    for (int i=0; i<n; i++) {
        if (str[i]!='P') continue;

        for (int j=i-k; j<=i+k; j++) {
            if (0<=j && j<n && str[j]=='H') {
                str[j]='.';
                ans++;
                break;
            }
        }
    }
    cout << ans;
}