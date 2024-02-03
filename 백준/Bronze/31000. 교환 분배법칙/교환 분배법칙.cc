#include <iostream>
#include <cmath>
using namespace std;

int n,ans=0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=-n; i<0; i++) {
    for (int j=-n; j<=n; j++) {
      if (-n<=1-i-j && 1-i-j<=n) ans++;
    }  
  }
  ans+=pow(2*n+1,2);
  for (int i=1; i<=n; i++) {
    for (int j=-n; j<=n; j++) {
      if (-n<=1-i-j && 1-i-j<=n) ans++;
    }    
  }
  cout << ans;
}
  