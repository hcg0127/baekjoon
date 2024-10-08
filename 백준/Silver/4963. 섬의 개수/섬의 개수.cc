#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int w,h,dx[8]={0,0,-1,-1,-1,1,1,1},dy[8]={-1,1,-1,0,1,-1,0,1};
bool board[50][50],visit[50][50];

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x,y});
    visit[x][y] = true;
    while (!q.empty()) {
        auto [a,b] = q.front();
        q.pop();
        for (int i=0; i<8; i++) {
            int cx=a+dx[i],cy=b+dy[i];
            if (cx<0 || cy<0 || cx>=w || cy>=h || visit[cx][cy] || !board[cx][cy]) continue;
            q.push({cx,cy});
            visit[cx][cy] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> h >> w;
        if (w==0 && h==0) break;
        fill(&board[0][0],&board[50][0],0);
        for (int i=0; i<w; i++)
            for (int j=0; j<h; j++) cin >> board[i][j];
        
        fill(&visit[0][0],&visit[50][0],0);
        int ans = 0;
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (board[i][j] && !visit[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }
}