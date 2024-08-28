#include <iostream>
#include <algorithm>
using namespace std;

int n,mx,dice[10001][7];

int sum_mx(int idx, int up, int down) {
    int tmp=0;

    for (int i=0; i<6; i++) {
        if (i==up || i==down) continue;
        tmp = max(tmp,dice[idx][i]);
    }

    return tmp;
}

int counter(int idx) {
    if (idx==0 || idx==5) return 5-idx;
    else if (idx==2 || idx==4) return 6-idx;
    else return 4-idx;
}

int uptodown(int idx, int up_num) {
    for (int i=0; i<6; i++) {
        if (dice[idx][i]==up_num) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> dice[i][0] >> dice[i][1] >> dice[i][2] >> dice[i][3] >> dice[i][4] >> dice[i][5];
    }

    for (int i=0; i<6; i++) { // 1번 주사위 윗면 결정 (a&f, b&d, c&e)
        int sum=0,up_idx=i,down_idx=counter(up_idx);

        for (int j=0; j<n; j++) { // 1번 ~ n번 주사위까지 올리면서 최댓값 더하기
            sum += sum_mx(j,up_idx,down_idx);

            // 주사위 위아래 인덱스 갱신
            down_idx = uptodown(j+1,dice[j][up_idx]);
            up_idx = counter(down_idx);
        }

        mx = max(mx,sum);
    }

    cout  << mx;
}