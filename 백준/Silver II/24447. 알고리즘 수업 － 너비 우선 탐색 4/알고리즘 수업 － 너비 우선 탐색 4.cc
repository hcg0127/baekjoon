#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long int n,m,r,u,v,cnt=1,ans=0,t[100001]={},d[100001]={};
vector<int> edge[100001];

void bfs(int e) {
  queue<int> q;
  q.push(e);
  while (!q.empty()) {
    int cur=q.front();
    q.pop();
    for (auto i:edge[cur]) {
      if (d[i]==-1) {
        q.push(i);
        d[i]=d[cur]+1;
        t[i]=++cnt;
        ans+=d[i]*t[i];
      }
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> r;
  for (int i=0; i<m; i++) {
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i=1; i<n; i++) sort(edge[i].begin(),edge[i].end());
  fill(d,d+n+1,-1);
  d[r]=0;
  t[r]=cnt;
  bfs(r);
}
  