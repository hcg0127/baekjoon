#include <iostream>
using namespace std;

int n,m,arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> arr[i];

    int l=0,r=n,ans=100001;
    while (l<=r) {
        int mid = (l+r)/2,last=0;
        bool flag = true;
        for (int i=0; i<m; i++) {
            if (arr[i]-mid>last) {
                flag = false;
                break;
            } 
            else {
                last = arr[i] + mid;
            }
        }
        if (n-last>0) flag = false;

        if (flag) {
            r = mid-1;
            ans = min(ans,mid);
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}