#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int n,m,x;
        long long int sum = 0;
        vector<int> a,b;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> x;
            a.push_back(x);
        }
        for (int i=0; i<m; i++) {
            cin >> x;
            b.push_back(x);
        }
        sort(b.begin(),b.end());

        for (int i=0; i<n; i++) {
            long long int l=0, r=m-1, mid;

            while (l+1<r) {
                mid = (l+r)/2;

                if (b[mid]<a[i]) l=mid;
                else r=mid;
            }

            sum += (abs(a[i]-b[l]<=abs(a[i]-b[r]))? b[l] : b[r]);
        }

        cout << sum << '\n';
    }
}