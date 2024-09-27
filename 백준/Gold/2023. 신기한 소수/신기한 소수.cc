#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

bool prime(int num) {
    for (int i=2; i<=num/2; i++) {
        if (num%i==0) return false;
    }
    return true;
}

void dfs(int num, int dep) {
    if (dep==n) {
        cout << num <<'\n';
        return;
    }

    for (int i=1; i<=9; i+=2) {
        int tmp = num*10+i;
        if (prime(tmp)) dfs(tmp,dep+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}