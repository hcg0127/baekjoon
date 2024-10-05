#include <iostream>
using namespace std;

int n,arr[200000],ans,type,visit[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    
    int l=0,r=0;
    bool flag = false;
    while (l<=r) {
        if (r>=n) break;

        if (!flag) {
            visit[arr[r]]++;
            if (visit[arr[r]]==1) type++;
        }
        else flag = false;
        
        if (type<=2) {
            ans = max(ans,r-l+1);
            r++;
        }
        else {
            visit[arr[l]]--;
            if (!visit[arr[l]]) type--;
            l++;
            flag = true;
        }
    }
    cout << ans;
}