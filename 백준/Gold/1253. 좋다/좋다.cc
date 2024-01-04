#include <iostream>
#include <algorithm>
using namespace std;

int n,num[2000]={},cnt=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> num[i];
    sort(num,num+n);
    for (int i=0; i<n; i++) {
        int left=0,right=n-1;
        while (left<right) {
            if (left==i) left++;
            if (right==i) right--;
            if (left==right) break;
            if (num[left]+num[right]>num[i]) {
                right--;
            }
            else if (num[left]+num[right]<num[i]) {
                left++;
            }
            else {
                cnt++;
                break;
            }
            if (left>=n-1) break;
        }
    }
    cout << cnt;
}