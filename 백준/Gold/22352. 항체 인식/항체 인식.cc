#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,a[30][30]={},b[30][30]={},anti[30][30]={},dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool check[30][30]={};

void bfs(pair<int,int> afbf, pair<int,int> p) {
    queue<pair<int,int>> q;
    auto [x,y]=p;
    auto [bf,af]=afbf;
    check[x][y]=true;
    q.push({x,y});
    anti[x][y]=af;
    while (!q.empty()) {
        auto [qx,qy]=q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int cx=qx+dx[i],cy=qy+dy[i];
            if (cx<0 || cy<0 || cx>n || cy>m || check[cx][cy] || anti[cx][cy]!=bf) continue;
            q.push({cx,cy});
            check[cx][cy]=true;
            anti[cx][cy]=af;
        }
    }
}

bool same() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            if (anti[i][j]!=b[i][j]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> a[i][j];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> b[i][j];
    }
    // 항체
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            copy(&a[0][0],&a[30][0],&anti[0][0]);
            if (same()) {
                cout << "YES";
                return 0;
            }
            if (!check[i][j] && anti[i][j]!=b[i][j]) {
                bfs({anti[i][j],b[i][j]},{i,j});
                if (same()) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}