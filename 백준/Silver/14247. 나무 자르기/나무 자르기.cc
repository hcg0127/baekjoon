#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int n,h[100001],a[100001];
long long int ans;
vector<pii> v;

bool cmp(pii a, pii b) {
    return a.second<b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) v.push_back({h[i],a[i]});
    sort(v.begin(),v.end(),cmp);

    for (int i=0; i<n; i++) ans += v[i].first + v[i].second * i;

    cout << ans;
}