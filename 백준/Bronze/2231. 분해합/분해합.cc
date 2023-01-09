#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  vector<int> m;
  
  for (int i=n-1; i>0; i--) {
    int sum=i, idx=i, tmp=i;
    while (idx > 0) {
      sum += idx % 10;
      idx /= 10;
    }
    if (sum == n) {
      m.push_back(tmp);
    }
  }
  int sol;
  if (!m.empty())
    sol = *min_element(m.begin(), m.end());
  else sol = 0;
  cout << sol;
}