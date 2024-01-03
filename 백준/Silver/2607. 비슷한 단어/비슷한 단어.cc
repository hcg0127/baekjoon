#include <iostream>
#include <algorithm>
using namespace std;

int n,p_arr[26]={},ans=0;
string pick,str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> pick;
    for (int i=0; i<pick.size(); i++) p_arr[pick[i]-'A']++;
    for (int i=1; i<n; i++) {
        cin >> str;
        int s_arr[26]={},p_copy[26],same=0,p_len=pick.size(),s_len=str.size();
        copy(p_arr,p_arr+26,p_copy);
        for (int j=0; j<str.size(); j++) s_arr[str[j]-'A']++;
        for (int j=0; j<s_len; j++) {
            if (p_copy[str[j]-'A']>0) {
                p_copy[str[j]-'A']--;
                same++;
            }
        }
        if (p_len==s_len) {
            if (same==p_len || same==p_len-1) ans++;
        }
        else if (p_len-1==s_len && same==p_len-1) ans++;
        else if (p_len+1==s_len && same==p_len) ans++;
        else continue;
    }
    cout << ans;
}