#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a,b,v;
  cin >> a >> b >> v;
  cout << (int)ceil((v-a)/(double)(a-b)) + 1;
}