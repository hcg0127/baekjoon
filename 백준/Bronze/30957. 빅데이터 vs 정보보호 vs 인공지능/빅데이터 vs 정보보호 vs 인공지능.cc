#include <iostream>
#include <algorithm>
using namespace std;

int n,a=0,b=0,s=0;
string str,ans="";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> str;
  for (int i=0; i<n; i++) {
    if (str[i]=='A') a++;
    else if (str[i]=='B') b++;
    else s++;
  }
  if (a==b && b==s) cout << "SCU";
  else {
    int mx=max({a,b,s});
    if (b==mx) ans+='B';
    if (s==mx) ans+='S';
    if (a==mx) ans+='A';
  }
  cout << ans;
}
  