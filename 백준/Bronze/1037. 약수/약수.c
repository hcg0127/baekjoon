#include <stdio.h>

int main(void) {
  int n,x;
  scanf("%d", &n);
  int arr[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &x);
    arr[i] = x;
  }
  int max = arr[0], min = arr[0];
  for (int i=0; i<n; i++) {
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }
  printf("%d\n", max * min);
  
}