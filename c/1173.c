#include <stdio.h>

int main() {
  int N, m, M, T, R, C, ans, work;
  scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
  C = m;
  work = 0;
  if(M-m<T) {
    ans = -1;
  } else if(m+(T*N)<=M) {
    ans = N;  
  } else {
    int set = (M-m)/T;
    C += set*T;
    work += set;
    ans = set;
    while(work<N) {
      while(C+T>M) {
        C -= R;
        ans += 1;
        if(C<m) {
          C = m;
        }
      }
      work += 1;
      C += T;
      ans += 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}