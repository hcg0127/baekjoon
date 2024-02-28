#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,k,arr[100001]={},visit[100001]={};

void bfs(int x) {
  queue<int> q;
  q.push(x);
  arr[x]=0;
  visit[x]=1;
  while (!q.empty()) {
    int cur = q.front(),dx[3]={cur-1,cur+1,cur*2};
    q.pop();
    for (int i=0; i<3; i++) {
      if (dx[i]<0 || dx[i]>100000) continue;
      if (arr[dx[i]]!=-1) {
        if (arr[dx[i]]==arr[cur]+1) visit[dx[i]]+=visit[cur];
      }
      else {
        q.push(dx[i]);
        visit[dx[i]]=visit[cur];
        arr[dx[i]]=arr[cur]+1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  fill(arr,arr+100001,-1);
  if (n==k) cout << 0 << '\n' << 1;
  else if (n>k) cout << n-k << '\n' << 1;
  else {
    bfs(n);
    cout << arr[k] << '\n' << visit[k];
  }
}
  