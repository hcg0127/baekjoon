#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x,cnt=0;
  cin >> x;
  string s = bitset<7>(x).to_string();
  for (int i=0; i<7; i++) {
    if (s[i] == '1') cnt++;
  }
  cout << cnt;
}