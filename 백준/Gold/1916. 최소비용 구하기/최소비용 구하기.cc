#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,u,v,w,s,e,dist[100001]={};
vector<pair<int,int>> vec[100001];

void dijk(int start) {
  priority_queue<pair<int,int>> pq;
  pq.push({0,start});
  dist[start]=0;
  while (!pq.empty()) {
    int d=-pq.top().first,cur=pq.top().second;
    pq.pop();
    if (dist[cur]<d) continue;
    for (int i=0; i<vec[cur].size(); i++) {
      int cost=d+vec[cur][i].second;
      if (cost<dist[vec[cur][i].first]) {
        dist[vec[cur][i].first]=cost;
        pq.push({-cost,vec[cur][i].first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    cin >> u >> v >> w;
    vec[u].push_back({v,w});
  }
  fill(dist,dist+100001,1e9);
  cin >> s >> e;
  dijk(s);
  cout << dist[e];
}