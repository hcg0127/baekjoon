#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m,bw_min=64,wb_min=64;
  cin >> n >> m;
  char board[n][m], w;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> w;
      board[i][j] = w;
    }
  }
  
  for (int i=0; i<n-7; i++) {
    for (int j=0; j<m-7; j++) {
      int bw_tmp=0;
      for (int x=i; x<i+8; x+=2) {
        for (int y=j; y<j+8; y+=2) {
          if (board[x][y] == 'B') { // bw
            bw_tmp++;
          }
          if (board[x+1][y] == 'W') {
            bw_tmp++;
          }
          if (board[x][y+1] == 'W') {
            bw_tmp++;
          }
          if (board[x+1][y+1] == 'B') {
            bw_tmp++;
          }
        }
      }
      if (bw_tmp < bw_min) bw_min = bw_tmp;
    }
  }
  for (int i=0; i<n-7; i++) {
    for (int j=0; j<m-7; j++) {
      int wb_tmp=0;
      for (int x=i; x<i+8; x+=2) {
        for (int y=j; y<j+8; y+=2) {
          if (board[x][y] == 'W') { // wb
            wb_tmp++;
          }
          if (board[x+1][y] == 'B') {
            wb_tmp++;
          }
          if (board[x][y+1] == 'B') {
            wb_tmp++;
          }
          if (board[x+1][y+1] == 'W') {
            wb_tmp++;
          }
        }
      }
      if (wb_tmp < wb_min) wb_min = wb_tmp;
    }
  }
  
  if (bw_min <= wb_min) cout << bw_min;
  else cout << wb_min;
}