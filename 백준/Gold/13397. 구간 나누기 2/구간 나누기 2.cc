#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x[5001],mx_x,ans=1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        mx_x = max(mx_x,x[i]);
    }

    int l=0, r=mx_x;
    while (l<=r) {
        int mid = (l+r)/2,mn=mx_x,mx=0,cnt=1;

        for (int i=0; i<n; i++) {
            mn = min(mn,x[i]);
            mx = max(mx,x[i]);

            if (mx-mn>mid) {
                cnt++;
                mn = mx_x;
                mx = 0;
                i--;
            }
        }

        if (cnt>m) {
            l = mid+1;
        }
        else {
            r = mid-1;
            ans = min(ans,mid);
        }
    }

    cout << ans;
}