#include <iostream>
#include <algorithm>
using namespace std;

int n,m,tr[1000001],mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >>tr[i];
        mx = max(tr[i],mx);
    }

    long long int l=0,r=mx,ans=0;
    while (l<=r) {
        long long int mid = (l+r)/2,sum=0;
        for (int i=0; i<n; i++) {
            sum += (tr[i]-mid>0 ? tr[i]-mid : 0);
        }
        if (sum>=m) {
            l = mid+1;
            ans = max(ans,mid);
        }
        else {
            r = mid-1;
        }
    }
    cout << ans;
}