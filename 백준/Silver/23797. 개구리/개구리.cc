#include <iostream>
using namespace std;

string str;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> str;
  int str_s=str.size(),k=0,p=0;
  for (int i=0; i<str_s; i++) {
    if (str[i]=='K') {
      k++;
      if (p>0) p--;
    }
    else {
      p++;
      if (k>0) k--;
    }
  }
  cout << k+p;
}
  