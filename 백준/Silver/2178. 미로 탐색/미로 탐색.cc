#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,m,cnt=0;
int visit[100][100]={0,}, edge[100][100]={0,}, mp[100][100];
int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

void mr(int x, int y) {
  queue<pair<int,int>> q;
  q.push({x,y});
  visit[x][y] = 1;
  while (!q.empty()) {
    pair<int,int> cur = q.front();
    q.pop();
    for (int i=0; i<4; i++) {
      int cx=cur.first+dx[i], cy=cur.second+dy[i];
      if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
      if (visit[cx][cy]==0 && edge[cx][cy]==1) {
        q.push({cx,cy});
        mp[cx][cy]=mp[cur.first][cur.second]+1;
        visit[cx][cy]=1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      mp[i][j] = 1;  
    }  
  }
  for (int i=0; i<n; i++) {
    string x;
    cin >> x;
    for (int j=0; j<m; j++) {
      edge[i][j] = x[j] - '0';
    }
  }
  mr(0,0);
  cout << mp[n-1][m-1];
}