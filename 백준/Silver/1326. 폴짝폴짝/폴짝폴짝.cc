#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

int n,arr[10001],a,b,ans=1e9;
bool visit[10001];

void bfs(int st, int en) {
    queue<pii> q;
    q.push({st,0});
    visit[st] = true;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i=x+arr[x]; i<=n; i+=arr[x]) {
            if (visit[i]) continue;
            if (i==en) ans = min(ans,y+1);
            q.push({i,y+1});
            visit[i] = true;
        }
        for (int i=x-arr[x]; i>=1; i-=arr[x]) {
            if (visit[i]) continue;
            if (i==en) ans = min(ans,y+1);
            q.push({i,y+1});
            visit[i] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> a >> b;

    if (a==b) {
        cout << 0;
        return 0;
    }
    bfs(a,b);

    if (ans==1e9) ans = -1;
    cout << ans;
}