#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long int x,y,d,ans=0;
        cin >> x >> y;
        d = y-x;
        
        int mx = sqrt(d);
        for (int i=1; i<mx; i++) {
            d -= i*2;
            ans +=2;
        }
        for (int i=mx; i>0; i--) {
            ans += d/i;
            d -= d/i * i;
        }

        cout << ans << '\n';
    }
}