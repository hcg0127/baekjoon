#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k, n;
  stack<int> q;
  cin >> k;
  for (int i=0; i<k; i++) {
    cin >> n;
    if (n != 0) q.push(n);
    else q.pop();
  }
  
  int sum = 0;
  if (!q.empty()) {
    while (!q.empty()) {
      sum += q.top();
      q.pop();
    }
    cout << sum;
  }
  else cout << 0;
}