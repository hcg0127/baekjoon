#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b) {
  if (a.first == b.first) return a.second < b.second;
  else return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<pair<int, string>> v_p;
  vector<string> v_s;
  string x;
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x;
    if (find(v_s.begin(), v_s.end(), x) == v_s.end()) {
      v_s.push_back(x);
      int size = x.length();
      v_p.push_back({size, x});
    }
  }
  
  sort(v_p.begin(), v_p.end(), cmp);
  int s = v_p.size();
  for (int i=0; i<s; i++) {
    cout << v_p[i].second << '\n';
  }
}