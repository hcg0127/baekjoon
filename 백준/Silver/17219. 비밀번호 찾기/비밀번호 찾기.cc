#include <iostream>
#include <map>
using namespace std;

int n,m;
string x,y,z;
map<string,string> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> x >> y;
    mp.insert({x,y});
  }
  for (int i=0; i<m; i++) {
    cin >> z;
    cout << mp.find(z)->second << '\n';
  }
}