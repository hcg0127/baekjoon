#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c,r,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool board[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> r >> c >> k;
    
    if (c * r < k) {
        cout << 0;
    }
    else if (k==1) {
        cout << 1 << ' ' << 1;
    }
    else {
        int x=1,y=1,d=0,num=1;
        board[x][y]=true;
        while (1) {
            int cx=x+dx[d],cy=y+dy[d];
            if (cx>r || cx<=0 || cy>c || cy<=0 || board[cx][cy]) d = (d+1) % 4;
            x += dx[d];
            y += dy[d];
            board[x][y] = true;
            num++;
            if (num==k) break;
        }

        cout << x << ' ' << y;
    }
}