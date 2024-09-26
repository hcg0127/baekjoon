#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
bool visit[26];
vector<char> v;

void dfs(int dep, int idx, int a, int b, string tmp) {
    if (dep==l) {
        if (a>=1 && b>=2) cout << tmp << '\n';
        return;
    }

    for (int i=idx; i<c; i++) {
        char ch = v[i];
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') dfs(dep+1,i+1,a+1,b,tmp+ch);
        else dfs(dep+1,i+1,a,b+1,tmp+ch);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> l >> c;
    char ch;
    for (int i=0; i<c; i++) {
        cin >> ch;
        v.push_back(ch);
    }
    sort(v.begin(),v.end());

    dfs(0,0,0,0,"");
}