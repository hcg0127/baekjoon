#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    int t;
    cin >> t;
    while(t--) {
        int n,s,arr[200000];
        cin >> n >> s;
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);

        long long int l=0,r=arr[n-1],ans=0;
        while (l<=r) {
            long long int mid=(l+r)/2,cnt=1,sum=0,last=0;

            for (int i=0; i<n; i++) {
                sum = arr[i] - arr[last];

                if (sum>=mid) {
                    last = i;
                    cnt++;
                }
            }

            if (cnt>=s) {
                l = mid+1;
                ans = max(ans,mid);
            }
            else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }
}