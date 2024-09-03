#include <iostream>
#define lint long long
using namespace std;

lint n,m,k;
lint level[100001];
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> level[i];
	}
	
	lint left = 0, right = m, ans = -1;
	while(left <= right){
		lint mid = (left+right)/2;
		lint cnt = 0, l = 0, r = 0, s = 0, v = 0;
		while(l <= r && r < n){
			if(l == r) {
				s = level[l]+mid;
				if(s >= m) {
					cnt++;
				}
				r++;
				s += (level[r]+mid);
				continue;
			}
			if(s >= m) {
				cnt += (n-r);
				s -= (level[l]+mid);
				l++;
			}
			else {
				r++;
				s += (level[r]+mid);
			}
		}
		if(cnt >= k) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	cout << ans;
}