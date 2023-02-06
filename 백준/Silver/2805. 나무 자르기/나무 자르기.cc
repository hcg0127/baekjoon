#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n,m;
  cin >> n >> m;
  long long tree[n];
  for (int i=0; i<n; i++) {
    cin >> tree[i];
  }

  int l=0, r=*max_element(tree,tree+n),result=0;
  while (l<=r) {
    long long sum=0,mid=(l+r)/2;
    for (int i=0; i<n; i++) {
      if (tree[i]-mid>0) sum+=tree[i]-mid;
    }
    if (sum >= m) {
      if (result<mid) result = mid;
      l=mid+1;
    }
    else r=mid-1;
  }
  cout << result;
}