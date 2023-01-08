#include <stdio.h>

int n,k;
int f(int n, int k);
int f(int n, int k) {
  if (k == 0) return 1;
  else {
    if (n == k) return 1;
    else if (n > k) return f(n-1, k-1) + f(n-1,k);
  }
}
int main(void) {
  scanf("%d %d", &n, &k);
  printf("%d\n", f(n,k));
}