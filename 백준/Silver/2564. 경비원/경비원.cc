#include <iostream>
#include <vector>
using namespace std;

int x,y,n,a,d,dg,ans;
vector<int> v;

int dton(int dir, int num) {
    if (d==1) return num;
    else if (d==4) return num+x;
    else if (d==2) return x-num+x+y;
    else return y-a+2*x+y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> n;
    for (int i=0; i<n; i++) {
        cin >> d >> a;
        v.push_back(dton(d,a));
    }
    cin >> d >> a;
    dg = dton(d,a);

    for (int i=0; i<n; i++) {
        int tmp = abs(v[i]-dg);
        ans += min(tmp,2*x+2*y-tmp);
    }
    cout << ans;
}