#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,x,x_sum,ans=1e9+1,mx;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
        x_sum += x;
        mx = max(mx,x);
    }

    int l=mx-1,r=x_sum+1;
    while (l+1<r) {
        int mid=(l+r)/2, sum=0, cnt=0;

        for (int i=0; i<n; i++) {
            sum+=v[i];
            if (sum>mid) {
                cnt++;
                sum=v[i];
            }
        }
        if (sum<=mid) cnt++;
        
        if (cnt>m) {
            l=mid;
        }
        else {
            r=mid;
            ans = min(ans,mid);
        }

    }

    cout << ans;
}