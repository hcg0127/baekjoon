#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,x,mx_x,ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
        mx_x = max(x,mx_x);
    }
    cin >> m;

    int l=0,r=mx_x+1;
    while (l+1<r) {
        int mid=(l+r)/2, sum=0;

        for (int i=0; i<n; i++)
            sum += (v[i]<=mid ? v[i] : mid);
        
        if (sum>m) {
            r=mid;
        }
        else {
            l=mid;
            ans = max(ans, mid);
        }

    }

    cout << ans;
}