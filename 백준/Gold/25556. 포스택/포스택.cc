#include <iostream>
#include <vector>
using namespace std;

int n,x;
vector<int> st(4);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        bool flag=false;
        for (int i=0; i<4; i++) {
            if (st[i]<x) {
                st[i]=x;
                flag=true;
                break;
            }
        }
        if (!flag) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}