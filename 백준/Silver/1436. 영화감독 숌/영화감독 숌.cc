#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,cnt=0;
  cin >> n;
  for (int i=666; ; i++) {
    if (to_string(i).find("666") != string::npos) cnt++;
    if (cnt == n) {
      cout << i;
      break;
    }
  }
}