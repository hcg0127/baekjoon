#include <stdio.h>
#include <string.h>

int main(void) {
  int t_sum=0;
  char dial[15]; // 대 65~90
  scanf("%s", dial);
  int len = strlen(dial);
  for (int i=0; i<len; i++) {
    if (dial[i] == 'A' || dial[i] == 'B' || dial[i] == 'C') t_sum+=2;
    else if (dial[i] == 'D' || dial[i] == 'E' || dial[i] == 'F') t_sum+=3;
    else if (dial[i] == 'G' || dial[i] == 'H' || dial[i] == 'I') t_sum+=4;
    else if (dial[i] == 'J' || dial[i] == 'K' || dial[i] == 'L') t_sum+=5;
    else if (dial[i] == 'M' || dial[i] == 'N' || dial[i] == 'O') t_sum+=6;
    else if (dial[i] == 'P' || dial[i] == 'Q' || dial[i] == 'R' || dial[i] == 'S') t_sum+=7;
    else if (dial[i] == 'T' || dial[i] == 'U' || dial[i] == 'V') t_sum+=8;
    else if (dial[i] == 'W' || dial[i] == 'X' || dial[i] == 'Y' || dial[i] == 'Z') t_sum+=9;
  }
  printf("%d", t_sum+len);
}