#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> t;
  while (t--) {
    vector<int> m, d, n(10);
    int ans=0;
    for (int i=0; i<10; i++) {
      cin >> n[i];
      if (i!=0 && n[i]==0) {
        m.push_back(i);
        d.push_back(i);
      }
    }
    if (n[1]==0) {
      m.push_back(11);
      if (n[0]==0) m.push_back(10);
      if (n[2]==0) m.push_back(12);
      for (int i=0; i<10; i++) {
        if (n[i]==0) d.push_back(10+i);
      }
    }
    if (n[2]==0) {
      for (int i=0; i<10; i++) {
        if (n[i]==0) d.push_back(20+i);
      }
    }
    if (n[3]==0) {
      if (n[0]==0) d.push_back(30);
      if (n[1]==0) d.push_back(31);
    }
    for (auto i:m) {
      if (i==4 || i==6 || i==9 || i==11) {
        if (n[1]==0 && n[3]==0) ans-=1;
      }
      else if (i==2) {
        if (n[3]==0) {
          if (n[0]==0) ans-=1;
          if (n[1]==0) ans-=1;
        } 
      }
    }
    cout << ans+m.size()*d.size() << '\n';
  }
}
  