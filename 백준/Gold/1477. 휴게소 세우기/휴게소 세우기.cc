#include <iostream>
#include <algorithm>
using namespace std;

int n,m,L,arr[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> L;
    arr[0] = 0;
    arr[n+1] = L;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr,arr+n+1);

    int l=1,r=L-1,mn=L;
    while (l<=r) {
        int mid=(l+r)/2,tmp_m=0;
        for (int i=0; i<n+1; i++) {
            int tmp = arr[i+1] - arr[i];
            if (tmp>=mid) {
                tmp_m += (tmp%mid==0 ? tmp/mid-1 : tmp/mid);
            }
        }
        if (tmp_m<=m) {
            mn = min(mn,mid);
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << mn;
}