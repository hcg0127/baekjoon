#include <iostream>
using namespace std;

int n,x,v[200001]={},mn;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x;
    if (i==0) {
      v[0]=0;
      mn=x;
    }
    else {
      if (x<mn) mn=x;
      v[i]=(x-mn)>v[i-1] ? x-mn : v[i-1];
    }
    cout << v[i] << ' ';
  }
}
  