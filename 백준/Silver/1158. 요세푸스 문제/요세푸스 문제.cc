#include <iostream>
#include <deque>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,k;
  cin >> n >> k;
  deque<int> y;
  int sol[n];
  for (int i=0; i<n; i++) {
    y.push_back(i+1);
  }
  int a=0;
  while (y.size() != 1) {
    for (int i=0; i<k-1; i++) {
      y.push_back(y.front());
      y.pop_front();
    }
    sol[a++] = y.front();
    y.pop_front();
  }
  sol[n-1] = y.front();

  cout << '<' << sol[0];
  for (int i=1; i<n; i++) {
    cout << ", " << sol[i];
  }
  cout << '>';
}