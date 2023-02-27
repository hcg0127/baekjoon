#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,x,y,visit[1001]={0,},cnt=0;
vector<int> edge[1001];

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (visit[cur] == 1) continue;
    visit[cur] = 1;
    for (int i=0; i<edge[cur].size(); i++) {
      if (visit[edge[cur][i]] == 0) {
        q.push(edge[cur][i]);
      }
    }
  }
  cnt++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> v;
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (int i=1; i<=n; i++) {
    if (visit[i]==1) continue;
    bfs(i);
  }
  cout << cnt;
}