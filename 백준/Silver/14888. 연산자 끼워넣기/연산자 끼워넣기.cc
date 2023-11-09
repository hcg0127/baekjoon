#include <iostream>
#include <algorithm>
using namespace std;

int n,j=1,nums[12]={},x,visit[11]={},arr[11]={},op[11]={};
long long int mn=1e10+1,mx=(-1)*1e10-1;

void dfs(int x, int lv) {
  if (lv==n-1) {
    long long int tmp=nums[1];
    for (int i=0; i<n-1; i++) {
      if (arr[i]==1) tmp+=nums[i+2];
      else if (arr[i]==2) tmp-=nums[i+2];
      else if (arr[i]==3) tmp*=nums[i+2];
      else tmp/=nums[i+2];
    }
    mx=max(mx,tmp);
    mn=min(mn,tmp);
  }
  for (int i=1; i<n; i++) {
    if (visit[i]==0) {
      visit[i]=1;
      arr[lv]=op[i];
      dfs(i+1,lv+1);
      visit[i]=0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=1; i<=n; i++) cin >> nums[i];
  for (int i=1; i<=4; i++) {
    cin >> x;
    for (int k=0; k<x; k++) {
      op[j]=i;
      j++;
    }
  }
  dfs(1,0);
  cout << mx << '\n' << mn;
}