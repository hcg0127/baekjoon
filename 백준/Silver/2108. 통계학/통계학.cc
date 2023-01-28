#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int mx = 0, ncnt[8001]={0,};
int getcnt();
int getcnt() {
  bool flag = false;
  int rst = 0;
  for (int i=0; i<=8000; i++) {
    if (ncnt[i] == mx) {
      if (flag == true) return i-4000;
      flag = true;
      rst = i-4000;
    }
  }
  return rst;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x, idx;
  vector<int> nums;
  double sum=0;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x;
    ncnt[x+4000]++;
    if (ncnt[x+4000] > mx) mx = ncnt[x+4000];
    mx = max(mx, ncnt[x+4000]);
    nums.push_back(x);
    sum += x;
  }
  
  sort(nums.begin(), nums.end());

  if (round(sum/n) == -0) cout << 0 << '\n';
  else cout << round(sum/n) << '\n';
  cout << nums[n/2] << '\n';
  cout << getcnt() << '\n';
  cout << nums[n-1] - nums[0] << '\n';

}