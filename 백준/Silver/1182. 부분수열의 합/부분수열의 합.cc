#include <iostream>
using namespace std;

int n,s,cnt=0,nums[20]={};

void dfs(int x, long long int sm) {
  if (x==n) {
    if (sm==s) cnt++;
    return;
  }
  dfs(x+1,sm+nums[x]);
  dfs(x+1,sm);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> s;
  for (int i=0; i<n; i++) cin >> nums[i];
  dfs(0,0);
  if (s==0) cnt--;
  cout << cnt;
}