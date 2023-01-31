#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,x;
  int nums[10001] = {0,};
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x;
    nums[x]++;
  }
  for (int i=1; i<10001; i++) {
    if (nums[i] != 0) {
      while (nums[i] != 0) {
        cout << i << '\n';
        nums[i]--;
      }
    }
  }
}