#include <iostream>
using namespace std;

int n,m,x,y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int nums[n],sum[n];
  for (int i=0; i<n; i++) {
    cin >> nums[i];
    if (i==0) sum[0]=nums[0];
    else sum[i]=sum[i-1]+nums[i];
  }
  for (int i=0; i<m; i++) {
    cin >> x >> y;
    if (x==y) cout << nums[x-1] << '\n';
    else {
      if (x==1) cout << sum[y-1] << '\n';
      else cout << sum[y-1]-sum[x-2] << '\n';
    }
  }
}