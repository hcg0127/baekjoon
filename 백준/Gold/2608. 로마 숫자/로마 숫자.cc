#include <iostream>
using namespace std;

string a,b;
int sum=0;

void count(int n, string str) {
    for (int i=0; i<n; i++) {
        if (str[i]=='M') sum+=1000;
        else if (str[i]=='D') sum+=500;
        else if (str[i]=='C') {
            if (str[i+1]=='M') {
                sum+=900;
                i+=1;
            }
            else if (str[i+1]=='D') {
                sum+=400;
                i+=1;
            }
            else sum+=100;
        }
        else if (str[i]=='L') sum+=50;
        else if (str[i]=='X') {
            if (str[i+1]=='L') {
                sum+=40;
                i+=1;
            }
            else if (str[i+1]=='C') {
                sum+=90;
                i+=1;
            }
            else sum+=10;
        }
        else if (str[i]=='V') sum+=5;
        else if (str[i]=='I') {
            if (str[i+1]=='V') {
                sum+=4;
                i+=1;
            }
            else if (str[i+1]=='X') {
                sum+=9;
                i+=1;
            }
            else sum+=1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    count(a.size(),a);
    count(b.size(),b);
    cout << sum << "\n";
    int nums[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string arr[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"},ans="";
    bool check[13]={};
    while (sum) {
        for (int i=0; i<13; i++) {
            int d=sum/nums[i];
            if (i==3 && check[1] || i==7 && check[5] || i==11 && check[9]) continue;
            if (d>0) {
                check[i]=true;
                sum%=nums[i];
                while (d--)
                    ans+=arr[i];
            }
        }
    }
    cout << ans;
}