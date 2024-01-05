#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t,n,a,b,c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t >> n;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        pq.push({c,{-a,b}});
    }
    while (t--) {
        int x=pq.top().first,y=(-1)*pq.top().second.first,z=pq.top().second.second;
        if (z>0) {
            cout << y << '\n';
            pq.pop();
            z--;
            x--;
            if (z>0)
                pq.push({x,{(-1)*y,z}});
        }
    }
}