#include <iostream>
#include <vector>
using namespace std;

int x,y,n,a,d,dg,ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> n;
    for (int i=0; i<n; i++) {
        cin >> d >> a;
        if (d==1) v.push_back(a);
        else if (d==4) v.push_back(a+x);
        else if (d==2) v.push_back(x-a+x+y);
        else v.push_back(y-a+2*x+y);
    }
    cin >> d >> a;
    if (d==1) dg = a;
    else if (d==4) dg = a+x;
    else if (d==2) dg = x-a+x+y;
    else dg = y-a+2*x+y;

    for (int i=0; i<n; i++) {
        int tmp = abs(v[i]-dg);
        ans += min(tmp,2*x+2*y-tmp);
    }
    cout << ans;
}