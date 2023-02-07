#include <iostream>
#include <deque>
using namespace std;

int tw_plus(deque<int> d, int num) {
  int tw_p=0;
  while (d.front() != num) {
    tw_p++;
    d.push_back(d.front());
    d.pop_front();
  }
  return tw_p;
}
int th_plus(deque<int> d, int num) {
  int th_p=0;
  while (d.front() != num) {
    th_p++;
    d.push_front(d.back());
    d.pop_back();
  }
  return th_p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m;
  cin >> n >> m;
  deque<int> d;
  for (int i=0; i<n; i++) {
    d.push_back(i+1);
  }
  int sel[m];
  for (int i=0; i<m; i++) {
    cin >> sel[i];
  }

  int on=0,mx=0,idx=0;
  while (on != m) {
    int tw=0, th=0;
    if (d.front() == sel[idx]) {
      d.pop_front();
      idx++;
      on++;
    }
    else {
      tw = tw_plus(d,sel[idx]);
      th = th_plus(d,sel[idx]);
      if (tw >= th) {
        mx+=th;
        while (d.front() != sel[idx]) {
          d.push_back(d.front());
          d.pop_front();
        }
      }
      else {
        mx+=tw;
        while (d.front() != sel[idx]) {
          d.push_front(d.back());
          d.pop_back();
        }
      }
    }
  }
  cout << mx;
}