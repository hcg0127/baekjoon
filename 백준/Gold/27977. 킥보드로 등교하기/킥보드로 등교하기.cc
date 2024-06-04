#include <iostream>
using namespace std;

int l,n,k,diff = -1;
int arr[100002];

int main() {
	cin >> l >> n >> k;
	arr[0] = 0, arr[n+1] = l;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n+1; i++){
		diff = max(diff,arr[i]-arr[i-1]);
	}
	
	int ans = l;
	int left = diff, right = l;
	while(left <= right){
		int mid = (left+right)/2;
		int cnt = 0;
		int tmp = 0;
		for(int i = 1; i <= n+1; i++){
			if(arr[i]-tmp > mid){
				cnt++;
				if(arr[i]-tmp == mid) tmp = arr[i];
				else tmp = arr[i-1];
			}
		}
		if(cnt > k) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = min(ans,mid);
		}
	}
	cout << ans;
}