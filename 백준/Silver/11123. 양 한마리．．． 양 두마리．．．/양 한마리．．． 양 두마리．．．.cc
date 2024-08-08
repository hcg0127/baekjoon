#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

int t,h,w,board[100][100],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool visit[100][100];

void bfs(int a, int b) {
    queue<pii> q;
    q.push({a,b});
    visit[a][b] = true;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx<0 || cx>=h || cy<0 || cy>=w || visit[cx][cy] || board[cx][cy]==0) continue;
            q.push({cx,cy});
            visit[cx][cy] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int ans=0;
        string str;
        fill(&board[0][0],&board[100][0],0);
        fill(&visit[0][0],&visit[100][0],false);
        cin >> h >> w;
        for (int i=0; i<h; i++) {
            cin >> str;
            for (int j=0; j<w; j++) {
                board[i][j] = (str[j]=='#'? 1 : 0);
            }
        }

        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (board[i][j]==1 && !visit[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}