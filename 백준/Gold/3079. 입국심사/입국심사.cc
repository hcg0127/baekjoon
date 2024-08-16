#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n,m,x,mn=1e9+1,mx,ans=1e18+1;
vector<int> v;

bool check(long long int mid) {
    long long int cnt=0;

    for (int i=0; i<n; i++) {
        cnt += mid/v[i];
        if (cnt>=m)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
        mx = max(x,mx);
        mn = min(x,mn);
    }

    long long int l=0, r=mx*m;
    while (l<=r) {
        long long int mid=(l+r)/2,cnt=0;

        if (check(mid)) {
            r=mid-1;
            ans = min(mid,ans);
        }
        else {
            l=mid+1;
        }
    }

    cout << ans;
}