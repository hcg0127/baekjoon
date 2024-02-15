#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,x,cnt=0,day=0;
vector<int> v;

bool same() {
  int tmp=v[0];
  for (int i=1; i<n; i++) {
    if (v[i]!=tmp) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> x;
    v.push_back(x);
  }
  while (1) {
    if (same()) break;
    int mn=2001;
    for (int i=0; i<k+1; i++) {
      mn=min(mn,v[i]);
    }
    cnt+=v[n-1]-mn;
    v[n-1]=mn;
    day++;
    sort(v.begin(),v.end());
  }
  cout << cnt << ' ' << day;
}
  