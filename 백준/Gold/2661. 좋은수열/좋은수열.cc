#include <iostream>
#include <string>
using namespace std;

int n;
string str;

bool proper(string s) {
    int ss = s.size();
    for (int i=1; i<=ss/2; i++) {
        if (s.substr(ss-2*i,i)==s.substr(ss-i,i)) return false;
    }
    return true;
}

void dfs(int dep) {
    if (dep==n) {
        cout << str;
        exit(0);
    }
    for (int i=1; i<=3; i++) {
        int ss = str.size();
        if (str[ss-1]==i) continue;
        str.push_back('0' + i);
        if (proper(str)) dfs(dep+1);
        str.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dfs(0);
}