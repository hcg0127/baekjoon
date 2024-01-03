#include <iostream>
#include <vector>
using namespace std;

int n,x;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    v.push_back(1);
    for (int i=2; i<=n; i++) {
        cin >> x;
        v.insert(v.end()-x,i);
    }
    for (auto i:v) cout << i << ' ';
}