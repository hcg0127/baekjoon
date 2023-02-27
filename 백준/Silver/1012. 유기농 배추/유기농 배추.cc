#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int t,n,m,k,x,y,visit[50][50],edge[50][50];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void dfs(int a, int b) {
  visit[a][b] = 1;
  for (int i=0; i<4; i++) {
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

  cin >> t;
  for (int i=0; i<t; i++) {
    int cnt=0;
    cin >> n >> m >> k;
    for (int r=0; r<50; r++) {
      for (int c=0; c<50; c++) {
        visit[r][c]=0;
        edge[r][c]=0;
      }
    }
    while (k--) {;
      cin >> x >> y;
      edge[x][y] = 1;
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (edge[i][j] == 1 && visit[i][j] == 0) {
          cnt++;
          dfs(i,j);
        }
      }
    }
    cout << cnt << '\n';
  }
}