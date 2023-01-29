#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  if (a.second== b.second) return a.first < b.first;
  else return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<pair<int,int>> v;
  int n,x,y;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x >> y;
    v.push_back({x,y});
  }
  sort(v.begin(), v.end(), cmp);
  for (int i=0; i<n; i++) {
    cout << v[i].first << ' ' << v[i].second << '\n';
  }
}