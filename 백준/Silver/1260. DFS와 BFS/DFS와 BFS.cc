#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n,m,s,x,y;
vector<int> edge[10001];
void dfs(int start) {
  stack<int> s;
  int visit[1001] = {0,};
  s.push(start);
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (visit[cur] == 1) continue;
    cout << cur << ' ';
    visit[cur] = 1;
    sort(edge[cur].begin(), edge[cur].end());
    for (int i=edge[cur].size(); i--; ) {
      if (visit[edge[cur][i]] == 0) s.push(edge[cur][i]);
    }
  }
}

/*
void dfs(int cur) {
  int visit[1001] = {0,};
  cout << cur << ' ';
  visit[cur] = 1;
  for (int to : edge[cur])
    if (visit[to] == 0) dfs(to);
}
*/

void bfs(int start) {
  queue<int> q;
  int visit[1001] = {0,};
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (visit[cur] == 1) continue;
    cout << cur << ' ';
    visit[cur] = 1;
    sort(edge[cur].begin(), edge[cur].end());
    for (int i=0; i<edge[cur].size(); i++) {
      if (visit[edge[cur][i]] == 0) q.push(edge[cur][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> s;
  for (int i=0; i<m; i++) {
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  dfs(s);
  cout << '\n';
  bfs(s);
}