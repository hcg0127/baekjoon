#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int t,r,c,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string str;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> r >> c >> str;
    int cnt=r*c,board[21][21]={},visit[21][21]={},d=0,x=0,y=0;
    for (int i=0; i<str.size(); i++) {
      board[i/c][i%c]=str[i]-'0';
    }
    string ss="",ans="";
    while (cnt) {
      if (ss.size()==5) {
        int tmp=0;
        for (int i=4; i>=0; i--) {
          tmp+=(ss[i]-'0')*pow(2,4-i);
        }
        if (tmp==0) ans+=" ";
        else ans+=(tmp+64);
        ss="";
      }
      ss+=to_string(board[x][y]);
      visit[x][y]=1;
      cnt--;
      if (y+dy[d]>=c || y+dy[d]<0 || x+dx[d]>=r || x+dx[d]<0 || visit[x+dx[d]][y+dy[d]]==1) d=(d+1)%4;
      x+=dx[d];
      y+=dy[d];
    }
    if (ss.size()!=0) {
      int q=5-ss.size();
      while (q) {
        ss+="0";
        q--;
      }
      int tmp=0;
      for (int i=4; i>=0; i--) {
        tmp+=(ss[i]-'0')*pow(2,4-i);
      }
      if (tmp!=0) ans+=(tmp+64);
    }
    int nr=ans.find_first_not_of(' '),nl=ans.find_last_not_of(' ');
    ans.erase(0,nr);
    ans.erase(nl+1);
    cout << ans << '\n';
  }
}
  