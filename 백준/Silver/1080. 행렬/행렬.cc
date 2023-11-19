#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,ans=0;
  bool a[50][50]={},b[50][50]={};
  cin >> n >> m;
  string str;
  for (int i=0; i<n; i++) {
    cin >> str;
    for (int j=0; j<m; j++) {
      a[i][j]=(str[j]-'0'==0?false:true);
    }
  }
  for (int i=0; i<n; i++) {
    cin >> str;
    for (int j=0; j<m; j++) {
      b[i][j]=(str[j]-'0'==0?false:true);
    }
  }
  for (int i=0; i<n-2; i++) {
    for (int j=0; j<m-2; j++) {
      if (a[i][j]!=b[i][j]) {
        ans++;
        for (int x=i;x<i+3;x++) {
          for (int y=j; y<j+3; y++) {
            a[x][y]=!a[x][y];
          }
        }
      }
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j]!=b[i][j]) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
}