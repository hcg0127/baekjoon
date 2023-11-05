#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,s,t;
  cin >> n;
  vector<pair<int,int>> v;
  priority_queue<int,vector<int>,greater<>> pq;
  for (int i=0; i<n; i++) {
    cin >> s >> t;
    v.push_back({s,t});
  }
  sort(v.begin(),v.end());
  pq.push(v[0].second);
  for (int i=1; i<n; i++) {
    pq.push(v[i].second);
    if (pq.top()>v[i].first) continue;
    else pq.pop();
  }
  cout << pq.size();
}