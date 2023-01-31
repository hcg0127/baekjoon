#include <iostream>
#include <queue>
using namespace std;

int N, x;
string str;
queue<int> q;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false); // scanf, printf X

  cin >> N;
  for (int i = 1; i < N + 1; i++) {
    q.push(i);
  }

  if (q.size() > 1) {
    for (int i = 1; i < N; i++) {
      q.pop();
      if (q.size() > 1) {
        x = q.front();
        q.pop();
        q.push(x);
      } else {
        cout << q.back() << "\n";
      }
    }
  }
  else {
    cout << q.back() << "\n";
  }
}