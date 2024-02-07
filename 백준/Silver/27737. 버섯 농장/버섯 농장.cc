#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,init_m,m,k,board[100][100]={},dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool visit[100][100]={};
vector<int> v;

void bfs(int a, int b) {
  queue<pair<int,int>> q;
  q.push({a,b});
  visit[a][b]=true;
  int cnt=1;
  while (!q.empty()) {
    auto [x,y]=q.front();
    q.pop();
    for (int i=0; i<4; i++) {
      int cx=x+dx[i],cy=y+dy[i];
      if (cx<0 || cy<0 || cx>=n || cy>=n || board[cx][cy]==1 || visit[cx][cy]) continue;
      q.push({cx,cy});
      visit[cx][cy]=true;
      cnt++;
    }
  }
  v.push_back(cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> init_m >> k;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> board[i][j];
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (board[i][j]==0 && !visit[i][j]) bfs(i,j);
    }
  }
  m=init_m;
  for (auto i:v) {
    if (m<=0) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    if (i>=k) {
      if (i%k==0) m-=i/k;
      else m-=i/k+1;
    }
    else m-=1;
  }
  if (m==init_m) cout << "IMPOSSIBLE";
  else cout << "POSSIBLE" << '\n' << m;
}
  