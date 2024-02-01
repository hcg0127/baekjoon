#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    getline(cin,str);
    int ss=str.size();
    double ph=0,pg=0;
    for (int i=0; i<ss; i++) {
        if (str[i]=='H' || str[i]=='P' || str[i]=='Y') ph++;
        else if (str[i]=='S' || str[i]=='D') pg++;
        else if (str[i]=='A') {
            ph++; pg++;
        }
    }
    if (pg==0 && ph==0) cout << "50.00";
    else {
        double a=ph*100/(ph+pg)+0.0001;
        cout << fixed;
        cout.precision(2);
        cout << a;
    }
}