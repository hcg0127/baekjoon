#include <iostream>
#include <string>
#include <set>
using namespace std;

int board[5][5],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
set<string> s;

void dfs(int x, int y, string chr) {
    if (chr.size() == 6) {
        s.insert(chr);
        return;
    }
    for (int i=0; i<4; i++) {
        int cx=x+dx[i], cy=y+dy[i];
        if (cx<0 || cx>=5 || cy<0 || cy>=5) continue;
        dfs(cx,cy,chr+to_string(board[cx][cy]));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            cin >> board[i][j];

    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            dfs(i,j,to_string(board[i][j]));

    cout << s.size();
}