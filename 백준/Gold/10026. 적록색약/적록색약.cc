#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int n,cnt,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char board[100][100];
bool visit[100][100],mode;

void bfs(int a, int b, bool mode) {
    queue<pii> q;
    q.push({a,b});
    visit[a][b] = true;
    char init_c = board[a][b];
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx<0 || cx>=n || cy<0 || cy>=n || visit[cx][cy]) continue;
            if (mode) {
                if (init_c=='B') {
                    if (board[cx][cy]!=init_c) continue;
                }
                else {
                    if (board[cx][cy]=='B') continue;
                }
            }
            else {
                if (board[cx][cy]!=init_c) continue;
            }
            q.push({cx,cy});
            visit[cx][cy] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<n; j++) board[i][j] = str[j];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visit[i][j]) {
                bfs(i,j,0);
                cnt++;
            }
        }
    }
    cout << cnt << ' ';

    cnt = 0;
    fill(&visit[0][0],&visit[100][0],0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visit[i][j]) {
                bfs(i,j,1);
                cnt++;
            }
        }
    }
    cout << cnt;
}