#include <iostream>
#include <algorithm>
using namespace std;

int n,k,arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k; // n<=k
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n,greater<>());
    if (n==1) {
        cout << arr[0];
        return 0;
    }

    long long int l=0,r=arr[0],mx=0;
    while (l<=r) {
        long long int mid = (l+r)/2,cnt=0;
        if (mid==0 || k==0) break;
        for (int i=0; i<n; i++) {
            if (arr[i]<mid) break;
            cnt += arr[i]/mid;
        }
        if (cnt>=k) {
            mx = max(mx,mid);
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    cout << mx;
}