#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,m,k,x,y,visit[50][50],edge[50][50];
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};

void dfs(int a, int b) {
  visit[a][b] = 1;
  for (int i=0; i<8; i++) {
    int cx = a+dx[i], cy = b+dy[i];
    if (cx<0 || cy<0 || cx>=n || cy>=m)
      continue;
    if (visit[cx][cy]==0 && edge[cx][cy]==1)
      dfs(cx,cy);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (1) {
    cin >> m >> n;
    if (n == 0 && m == 0) break;
    int cnt=0;
    for (int r=0; r<50; r++) {
      for (int c=0; c<50; c++) {
        visit[r][c]=0;
        edge[r][c]=0;
      }
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        cin >> edge[i][j];
      }
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (edge[i][j]==1&&visit[i][j]==0) {
          cnt++;
          dfs(i,j);
        }
      }
    }
    cout << cnt << '\n';
  }
}