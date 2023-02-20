#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n,x;
  vector<char> pm;
  cin >> n;
  deque<int> que;
  for (int i=0; i<n; i++) {
    cin >> x;
    que.push_back(x);
  }
  que.push_back('!');
  stack<int> s;
  int idx = que.front();
  for (int i=1; i<=idx; i++) {
    s.push(i);
    pm.push_back('+');
  }
  int popc=0;
  while (popc != n) {
    if (s.empty()) {
      s.push(++idx);
      pm.push_back('+');
    }
    if (s.top() == que.front()) {
      s.pop();
      pm.push_back('-');
      que.pop_front();
      popc++;
    }
    else if (s.top() < que.front()) {
      s.push(++idx);
      pm.push_back('+');
    }
    else {
      cout << "NO";
      exit(0);
    }
  }
  for (auto i:pm) {
    cout << i << '\n';
  }
}