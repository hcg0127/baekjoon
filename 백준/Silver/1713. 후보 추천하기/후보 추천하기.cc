#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int n,m,x,cnt,score[101],post[101];
bool frame[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> x;

        if (frame[x]==0) { // 사진틀에 없음
            if (cnt<n) { // 사진틀에 넣기
                frame[x] = 1;
                post[x] = i;
                score[x]++;
                cnt++;
            }
            else { // 사진 대체
                int mn_rec=1001,mn_time=22,rep=0;
                for (int i=1; i<101; i++) {
                    if (frame[i]==1 && mn_rec > score[i]) {
                        mn_rec = score[i];
                        mn_time = post[i];
                        rep = i;
                    }
                    else if (frame[i]==1 && mn_rec == score[i]) {
                        if (post[i] > 0 && mn_time > post[i]) {
                            mn_time = post[i];
                            rep = i;
                        }
                    }
                }

                frame[rep] = 0;
                post[rep] = 0;
                score[rep] = 0;
                
                frame[x] = 1;
                post[x] = i;
                score[x]++;
            }
        }
        else { // 사진틀에 있음
            score[x]++;
        }
    }

    for (int i=1; i<101; i++) {
        if (frame[i]==1) cout << i << ' ';
    }
}