#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,a,b,x,ans;
vector<int> A,B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;
    for (int i=0; i<a; i++) {
        cin >> x;
        A.push_back(x);
    }
    for (int i=0; i<b; i++) {
        cin >> x;
        B.push_back(x);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    if (n%2==1) {
        ans += A.back();
        A.pop_back();
        n--;
        a--;
    }

    for (int i=0; i<n; i+=2) {
        int ax=0,bx=0;

        if (a>=2) {
            ax += A[a-1] + A[a-2];
        }
        if (b>=1) {
            bx += B[b-1];
        }

        if (ax > bx) {
            ans += ax;
            A.pop_back();
            A.pop_back();
            a-=2;
        }
        else {
            ans += bx;
            B.pop_back();
            b-=1;
        }
    }

    cout << ans;
}