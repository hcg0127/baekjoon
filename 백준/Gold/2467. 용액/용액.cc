#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,a,b,min=2000000001;
  cin >> n;
  vector<int> v(n);
  for (int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(),v.end());
  int l=0,r=n-1;
  while (l<r) {
    if (v[l]+v[r]>0) {
      if (abs(v[l]+v[r])<min) {
        min=abs(v[l]+v[r]);
        a=v[l];
        b=v[r];
      }
      r--;
    }
    else if (v[l]+v[r]<0) {
      if (abs(v[l]+v[r])<min) {
        min=abs(v[l]+v[r]);
        a=v[l];
        b=v[r];
      }
      l++;
    }
    else {
      a=v[l];
      b=v[r];
      break;
    }
  }
  cout << a << ' ' << b;
}