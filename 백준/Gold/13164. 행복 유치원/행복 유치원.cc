#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,x,ans;
vector<int> v,hd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    for (int i=1; i<n; i++) hd.push_back(v[i]-v[i-1]);
    sort(hd.begin(),hd.end());

    for (int i=0; i<n-k; i++) ans+=hd[i];

    cout << ans;
}