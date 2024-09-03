#include <iostream>
#include <algorithm>
using namespace std;

long long int n,c,arr[200001],ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> n >> c;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);

    int l=0,r=arr[n-1];
    while (l<=r) {
        long long int mid=(l+r)/2,sum=0,last=0,cnt=1;

        for (int i=0; i<n; i++) {
            sum = arr[i] - arr[last];
            
            if (sum>=mid) {
                last = i;
                cnt++;
                sum = 0;
            }
        }

        if (cnt>=c) {
            l = mid+1;
            ans = max(ans,mid);
        }
        else {
            r = mid-1;
        }
    }

    cout << ans;
}