#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int n,w,l,tr[1001];
queue<pii> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> w >> l;
    for (int i=0; i<n; i++) cin >> tr[i];

    int w_sum=0,in=0,left=0,tm;
    for (int i=1; ; i++) {
        if (!q.empty()) {
            auto [idx,tm] = q.front();
            if (tm==i) {
                w_sum -= tr[idx];
                q.pop();
            }
        }
        if (w_sum+tr[left]<=l) {
            q.push({left,i+w});
            w_sum += tr[left];
            left++;
            if (left>=n) {
                cout << i+w;
                return 0;
            }
        }
    }
}