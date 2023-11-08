#include <iostream>
#include <set>
#include <string>
using namespace std;

string str,tmp;
int n;
set<string> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> str;
  n=str.size();
  for (int i=0; i<n; i++) {
    for (int j=1; j<=n; j++) {
      tmp=str.substr(i,j);
      s.insert(tmp);
    }
  }
  cout << s.size();
}