#include <iostream>
#include <queue>
using namespace std;

int a,k,visit[1000001];

void bfs() {
    queue<int> q;
    q.push(a);
    visit[a] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int nums[2] = {cur+1,cur*2};
        for (int i=0; i<2; i++) {
            if (nums[i]<=k && visit[nums[i]]>visit[cur]+1) {
                visit[nums[i]] = visit[cur]+1;
                q.push(nums[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> k;
    fill(visit,visit+k+1,1e9);
    bfs();
    cout << visit[k];
}