#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t,n;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    switch(n) {
      case 1: cout << 1 << '\n'; break;
      case 2: cout << 2 << '\n'; break;
      case 3: cout << 4 << '\n'; break;
      case 4: cout << 7 << '\n'; break;
      case 5: cout << 13 << '\n'; break;
      case 6: cout << 24 << '\n'; break;
      case 7: cout << 44 << '\n'; break;
      case 8: cout << 81 << '\n'; break;
      case 9: cout << 149 << '\n'; break;
      case 10: cout << 274 << '\n'; break;
      default: break;
    }
  }
}