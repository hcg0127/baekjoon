#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,arr[11]={};
char vch[11];
string mx,mn;
vector<string> v;
bool visit[11];

bool check(char a, char b, char op) {
  if (op=='<') {if (a>b) return false;}
  else {if (a<b) return false;}
  return true;
}

void dfs(int lv, string num) {
  if (lv==n+1) {
    v.push_back(num);
    return;
  }
  for (int i=0; i<10; i++) {
    if (visit[i]==0) {
      if (lv==0 || check(num[lv-1], i+'0', vch[lv-1])){
        visit[i]=1;
        dfs(lv+1,num+to_string(i));
        visit[i]=0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i=0; i<n; i++) cin >> vch[i];
  dfs(0,"");
  sort(v.begin(),v.end());
  cout << v[v.size()-1] << '\n' << v[0];
}