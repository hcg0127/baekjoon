#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

int n,m,u,v,idx;
vector<vector<int>> edge;
vector<int> visit;

bool dfs(int idx, int before) {
    visit[idx] = true;

    for (auto i : edge[idx]) {
        int next = i;
        if (next==before) continue;
        if (visit[next]) return false;
        if (!dfs(next,idx)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    while (1) {
        cin >> n >> m;
        if (n==0 && m==0) break;
        
        int tree = 0;
        idx++;

        edge.assign(n+1, vector<int>(0,0));
        visit.assign(n+1, false);
        for (int i=0; i<m; i++) {
            cin >> u >> v;
            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
        }

        for (int i=1; i<=n; i++) {
            if (!visit[i] && dfs(i,0)) tree++;
        }

        cout << "Case " << idx;
        if (tree==0) cout << ": No trees.\n";
        else if (tree==1) cout << ": There is one tree.\n";
        else cout << ": A forest of " << tree << " trees.\n";
    }
}