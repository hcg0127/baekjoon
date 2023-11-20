#include <iostream>
#include <algorithm>
using namespace std;

int n,ans=100001,a,b;
bool arr[2][100001]={},tmp[100001]={};

bool tf() {
  for (int i=0; i<n; i++) {
    if (tmp[i]!=arr[1][i]) return false;
  }
  return true;
}

int swt(int lv) {
  int cnt=0;
  for (int i=0; i<n; i++) tmp[i]=arr[0][i];
  if (lv==1) {
    cnt++;
    tmp[0]=!tmp[0];
    tmp[1]=!tmp[1];
  }
  for (int i=1; i<n-1; i++) {
    if (tmp[i-1]!=arr[1][i-1]) {
      cnt++;
      tmp[i-1]=!tmp[i-1];
      tmp[i]=!tmp[i];
      tmp[i+1]=!tmp[i+1];
    }
  }
  if (tmp[n-2]!=arr[1][n-2]) {
    cnt++;
    tmp[n-2]=!tmp[n-2];
    tmp[n-1]=!tmp[n-1];
  }
  if (tf()) return cnt;
  else return 100001;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=0; i<2; i++) {
    string str;
    cin >> str;
    for (int j=0; j<n; j++) arr[i][j]=(str[j]-'0'==0?false:true);
  }
  ans=min(swt(1),swt(2));
  if (ans==100001) ans=-1;
  cout << ans;
}