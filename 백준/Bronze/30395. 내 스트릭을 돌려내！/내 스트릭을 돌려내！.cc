#include <iostream>
#include <algorithm>
using namespace std;

int n,p[1000]={},ans=0,mx=0;
bool flag=true;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> p[i];
    if (!flag && i>1 && p[i-2]==0) flag=true;
    if (p[i]==0 && flag) flag=false;
    else if (p[i]==0 && !flag) ans=0;
    else ans++;
    mx=max(mx,ans);
  }
  cout << mx;
}
  