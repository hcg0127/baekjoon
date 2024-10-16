#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,s,b,cnt;
string st;
vector<pair<string,pair<int,int>>> v;
bool visit[10];

void dfs(int dep, string str) {
    if (dep==3) {
        for (int i=0; i<n; i++) {
            int tmp_s=0, tmp_b=0;
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    if (str[j]==(v[i].first)[k]) {
                        if (j==k) tmp_s++;
                        else tmp_b++;
                    }
                }
            }
            if (tmp_s!=v[i].second.first || tmp_b!=v[i].second.second) return;
        }
        cnt++;
        return;
    }
    for (int i=1; i<=9; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(dep+1,str+to_string(i));
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> st >> s >> b;
        if (s==3) {
            cout << 1;
            return 0;
        }
        v.push_back({st,{s,b}});
    }

    dfs(0,"");

    cout << cnt;
}