#include <iostream>
#include <cstring>
using namespace std;

int cnt=0;

int recursion(const char * str, int l, int r) {
  cnt++;
  if (l>=r) return 1;
  else if (str[l]!=str[r]) return 0;
  else return recursion(str,l+1,r-1);
}

int isPalindrome(const char * str) {
  return recursion(str,0,strlen(str)-1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cnt=0;
    string s;
    cin >> s;
    cout << isPalindrome(s.c_str()) << ' ' << cnt << '\n';
  }
}