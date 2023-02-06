#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,cnt=0;
  cin >> n;
  for (int i=1; i<=n; i++) {
    int tmp=i,len=0;
    while (tmp>0) {
      len++;
      tmp/=10;
    }
    if (len == 1 || len == 2) cnt++;
    else {
      int h=i/100,t=(i/10)%10,o=i%10;
      if (h-t == t-o) cnt++;
    }
  }
  cout << cnt;
}