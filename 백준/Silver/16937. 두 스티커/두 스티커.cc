#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

int h,w,n,r,c,mx;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> h >> w >> n;
    for (int i=0; i<n; i++) {
        cin >> r >> c;
        if (r<=h && c<=w || r<=w && c<=h)
            v.push_back({r,c});
    }

    int vs = v.size();
    for (int i=0; i<vs; i++) {
        for (int j=i+1; j<vs; j++) {
            auto [r1,c1] = v[i];
            auto [r2,c2] = v[j];
            if (r1+r2 <= h && max(c1,c2) <= w || max(r1,r2) <= h && c1+c2 <= w)
                mx = max(mx, r1*c1+r2*c2);
            else if (r1+c2 <= h && max(c1,r2) <= w || max(r1,c2) <= h && c1+r2 <= w)
                mx = max(mx, r1*c1+r2*c2);
            else if (c1+r2 <= h && max(r1,c2) <= w || max(c1,r2) <= h && r1+c2 <= w)
                mx = max(mx, r1*c1+r2*c2);
            else if (c1+c2 <= h && max(r1,r2) <= w || max(c1,c2) <= h && r1+r2 <= w)
                mx = max(mx, r1*c1+r2*c2);
        }
    }

    cout << mx;
}