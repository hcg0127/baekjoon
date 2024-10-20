#include <iostream>
#include <algorithm>
using namespace std;

int n,m,dot[100001],x,y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> dot[i];
    sort(dot,dot+n);
    while (m--) {
        cin >> x >> y;
        cout << upper_bound(dot,dot+n,y) - lower_bound(dot,dot+n,x) << '\n';
    }
}