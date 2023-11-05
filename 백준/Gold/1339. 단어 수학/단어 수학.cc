#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,ans=0;
  cin >> n;
  string st;
  vector<int> v(26,0);
  for (int i=0; i<n; i++) {
    cin >> st;
    int ss=st.size()-1;
    for (int j=0; j<=ss; j++) v[st[j]-'A']+=(int)pow(10,ss-j);
  }
  sort(v.rbegin(),v.rend());
  for (int i=0; i<10; i++) ans+=v[i]*(9-i);
  cout << ans;
}