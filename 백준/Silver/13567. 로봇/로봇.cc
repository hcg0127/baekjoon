#include <iostream>
using namespace std;

int m,n,a,d,x,y,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    while (n--) {
        cin >> str >> a;
        if (str.compare("MOVE")==0) {
            for (int i=0; i<a; i++) {
                x+=dx[d];
                y+=dy[d];
            }
            if (x<0 || y<0 || x>=m || y>=m) {
                cout << -1;
                return 0;
            }
        }
        else {
            if (a==0) d=(d+1)%4;
            else d=(d+3)%4;
        }
    }
    cout << y << ' ' << x;
}