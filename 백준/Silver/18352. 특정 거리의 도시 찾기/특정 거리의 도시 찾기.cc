#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define pii pair<int,int>
using namespace std;

int n,m,k,x,a,b;
bool visit[300001];
vector<int> edge[300001];
set<int> s;

void bfs(int start) {
    queue<pii> q;
    q.push({start,0});
    visit[start] = true;
    while (!q.empty()) {
        auto [a,b] = q.front();
        q.pop();
        for (auto i : edge[a]) {
            if (visit[i]) continue;
            if (b==k-1) {
                s.insert(i);
                continue;
            }
            q.push({i,b+1});
            visit[i] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> n >> m >> k >> x;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
    }

    bfs(x);
    if (s.size()==0) cout << -1;
    else for (auto i : s) cout << i << '\n';
}