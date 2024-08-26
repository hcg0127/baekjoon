#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r,c,board[12][12],edge[2][2]={{12,12},{-1,-1}},dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool sea[12][12];
string str;

void check(int a, int b) {
    int cnt=0;
    for (int i=0; i<4; i++) {
        if (board[a+dx[i]][b+dy[i]]==0) cnt++;
    }
    
    if (cnt<=2) {
        sea[a][b] = false;
        if (board[a][b]==1) {
            edge[0][0] = min(a,edge[0][0]);
            edge[0][1] = min(b,edge[0][1]);
            edge[1][0] = max(a,edge[1][0]);
            edge[1][1] = max(b,edge[1][1]);
        }
    }
    else sea[a][b] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> r >> c;
    for (int i=1; i<=r; i++) {
        cin >> str;
        for (int j=1; j<=c; j++) board[i][j] = (str[j-1]=='X' ? 1 : 0);
    }

    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            check(i,j);
        }
    }

    for (int i=edge[0][0]; i<=edge[1][0]; i++) {
        for (int j=edge[0][1]; j<=edge[1][1]; j++) {
            cout << (!sea[i][j] && board[i][j]==1 ? 'X' : '.');
        }
        cout << '\n';
    }

}