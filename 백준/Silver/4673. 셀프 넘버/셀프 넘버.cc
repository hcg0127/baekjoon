#include <iostream>

using namespace std;

bool num[10001] = {false, };
int sum(int i);
int sum(int i) {
  int sum = i;
  while (i != 0) {
    sum += i % 10;
    i /= 10;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i=1; i<10001; i++) {
    int n = sum(i);
    if (n < 10001)
      num[n] = true;
  }
  
  for (int i=1; i<10001; i++) {
    if (!num[i]) {
      cout << i << "\n";
    }
  }
  return 0;
}