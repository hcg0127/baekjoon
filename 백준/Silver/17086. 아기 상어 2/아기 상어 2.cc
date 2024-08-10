#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

int n,m,board[50][50],mx=0,dx[8]={0,0,-1,-1,-1,1,1,1},dy[8]={-1,1,-1,0,1,-1,0,1};

void bfs(int a, int b, int d) {
    bool visit[50][50];
    fill(&visit[0][0], &visit[50][0], false);
    queue<pair<int,pii>> q;
    q.push({d,{a,b}});
    visit[a][b] = true;
    while (!q.empty()) {
        pair<int,pii> cur = q.front();
        q.pop();
        for (int i=0; i<8; i++) {
            int cx=cur.second.first+dx[i],cy=cur.second.second+dy[i];
            if (cx<0 || cx>=n || cy<0 || cy>=m || visit[cx][cy]) continue;
            if (board[cx][cy]==1) {
                mx = max(mx,cur.first+1);
                return;
            }
            q.push({cur.first+1,{cx,cy}});
            visit[cx][cy] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> board[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (board[i][j]==0)
                bfs(i,j,0);

    cout << mx;
}