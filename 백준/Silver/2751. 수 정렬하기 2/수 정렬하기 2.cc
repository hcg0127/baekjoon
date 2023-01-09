#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,x;
  cin >> n;
  vector<int> num;
  for (int i=0; i<n; i++) {
    cin >> x;
    num.push_back(x);
  }
  sort(num.begin(), num.end());
  for (int i=0; i<n; i++) {
    cout << num[i] << '\n';
  }
}