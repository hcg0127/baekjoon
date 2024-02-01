#include <iostream>
#include <algorithm>
using namespace std;

int n,c,jinju,arr[1000]={};
string d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> d >> c;
        if (d.compare("jinju")==0) jinju=c;
        arr[i]=c;
    }
    sort(arr,arr+n);
    cout << jinju << '\n';
    int x = upper_bound(arr,arr+n,jinju)-arr;
    cout << n-x;
}