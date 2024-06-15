#include <iostream>
#include <cmath>
using namespace std;

int n1,n2,n12;

int main() {
    cin >> n1 >> n2 >> n12;
    cout << floor((n1+1) * (n2+1) / (n12+1) - 1);
}