#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int board[9][9];
vector<pii> zeros;
bool found;

void printb() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}

bool proper(int x, int y, int num) {
    // row
    for (int i=0; i<9; i++) {
        if (i!=y && board[x][i]==num) return false;
    }

    // col
    for (int i=0; i<9; i++) {
        if (i!=x && board[i][y]==num) return false;
    }

    // grid
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int cx=x/3*3+i, cy=y/3*3+j;
            if ((cx!=x || cy!=y) && board[cx][cy]==num) return false;
        }
    }

    return true;
}

void dfs(int dep) {
    if (dep==zeros.size()) {
        printb();
        exit(0);
        return;
    }
    auto [a,b] = zeros[dep];
    for (int i=1; i<=9; i++) {
        board[a][b] = i;
        if (proper(a,b,i)) dfs(dep+1);
        board[a][b] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
            if (board[i][j]==0) zeros.push_back({i,j});
        }
    }
    
    dfs(0);
}