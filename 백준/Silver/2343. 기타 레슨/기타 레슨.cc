#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  long long int n,m,total=0;
  cin >> n >> m;
  long long int t[n];
  for (int i=0; i<n; i++) {
    cin >> t[i];
    total += t[i];
  }
  if (m==1) {
    cout << total;
    return 0;
  }
  long long int low=*max_element(t,t+n),high=total,ans=total;
  while (low+1<=high) {
    int mid = (low+high)/2,cnt=0,idx=0;
    for (cnt=1; cnt<=n; cnt++) {
      int sum=0;
      while (sum<mid) {
        sum+=t[idx++];
        if (idx>=n) break;
      }
      if (sum>mid) sum-=t[--idx];
      if (idx>=n) break;
    }
    if (cnt<=m) {
      high = mid;
      if (mid<ans) ans=mid;
    }
    else low = mid;
    if ((low+high)/2==mid) break;
  }
  cout << ans;
}