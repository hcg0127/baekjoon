#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[100000],ans=2000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);

    int l=0,r=0;
    while (l<=r) {
        if (r>=n) break;
        int tmp = arr[r] - arr[l];
        if (tmp>=m) {
            ans = min(ans,tmp);
            l++;
        }
        else {
            r++;
        }
    }
    
    cout << ans;
}