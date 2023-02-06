#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int nums[10] = {0,};
  while (n>0) {
    nums[n%10]++;
    n /= 10;
  }

  int tmp = nums[6]+nums[9];
  if (tmp % 2 == 0) {
    nums[6] = 0;
    nums[9] = tmp / 2;
  }
  else {
    nums[6] = 0;
    nums[9] = tmp / 2 + 1;
  }
  cout << *max_element(nums,nums+10);
}