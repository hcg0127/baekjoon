#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int board[21][21],dx[4]={0,1,1,1},dy[4]={1,0,1,-1};

bool cmp(pii x, pii y) {
    if (x.second==y.second) return x.first<y.first;
    else return x.second<y.second;
}

void check(int x, int y, int bw) {
    for (int d=0; d<4; d++) {
        int tmp_x=x,tmp_y=y;
        bool flag = true;
        vector<pii> v;
        v.push_back({x,y});
        for (int i=1; i<=4; i++) {
            tmp_x+=dx[d];
            tmp_y+=dy[d];
            if (tmp_x<=0 || tmp_y<=0 || tmp_x>19 || tmp_y>19 || board[tmp_x][tmp_y]!=bw) {
                flag = false;
                break;
            }
            v.push_back({tmp_x,tmp_y});
        }
        if (flag) {
            tmp_x+=dx[d];
            tmp_y+=dy[d];
            if (board[tmp_x][tmp_y]!=bw && board[x-dx[d]][y-dy[d]]!=bw) {
                sort(v.begin(),v.end(),cmp);
                cout << bw << '\n' << v[0].first << ' ' << v[0].second;
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=1; i<=19; i++)
        for (int j=1; j<=19; j++) cin >> board[i][j];
    
    for (int i=1; i<=19; i++)
        for (int j=1; j<=19; j++)
            if (board[i][j]!=0) check(i,j,board[i][j]);
    
    cout << 0;
}