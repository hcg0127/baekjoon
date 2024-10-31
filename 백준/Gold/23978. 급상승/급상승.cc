#include <iostream>
using namespace std;

long long int n,k,x,arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    long long int l=1,r=1500000000,ans=1e18;
    while (l<=r) {
        long long int mid=(l+r)/2,sum=(mid+1)*mid/2;
        for (int i=0; i<n-1; i++) {
            long long int tmp = arr[i+1]-arr[i], diff = min(mid,tmp);
            sum += mid*diff - (diff-1)*diff/2;
        }

        if (sum>=k) {
            r = mid-1;
            ans = min(ans,mid);
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}