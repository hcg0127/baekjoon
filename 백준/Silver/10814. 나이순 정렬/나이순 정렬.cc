#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct {
  int age;
  string name;
  int rank;
} sign;

bool cmp(sign a, sign b) {
  if (a.age == b.age) {
    return a.rank < b.rank;
  }
  else {
    return a.age < b.age;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<sign> s;
  int n, age_x;
  string name_x;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> age_x >> name_x;
    s.push_back({age_x, name_x, i+1});
  }
  sort(s.begin(), s.end(), cmp);
  int size = s.size();
  for (int i=0; i<size; i++) {
    cout << s[i].age << ' ' << s[i].name << '\n';
  }
}