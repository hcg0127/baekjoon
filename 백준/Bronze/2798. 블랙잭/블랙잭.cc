#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m,x;
  cin >> n >> m;
  int jack_max = 0;
  int cards[n];
  for (int i=0; i<n; i++) {
    cin >> x;
    cards[i] = x;
  }
  for (int i=0; i<n-2; i++) {
    for (int j=i+1; j<n-1; j++) {
      for (int k=j+1; k<n; k++) {
        int tmp = cards[i] + cards[j] + cards[k];
        if ((tmp > jack_max) && (tmp <= m)) jack_max = tmp;
      }
    }
  }
  cout << jack_max;
}