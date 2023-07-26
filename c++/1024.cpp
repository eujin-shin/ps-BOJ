#include <iostream>
using namespace std;

int main() {
  bool flag = false;
  int n, l, x, k;
  cin>>n>>l;
  for(int i=l; i<101; i++) {
    if(i%2 && n%i==0) {
      if(n/i>=i/2) {
        x = n/i-i/2;
        k = i;
        flag = true;
        break;
      }
    } else if(i%2==0 && (n+i/2)%i==0) {
      if(n/i>=i/2-1) {
        x = n/i-i/2+1;
        k = i;
        flag = true;
        break;
      }
    }
  }
  if(flag) {
    for(int i=0; i<k; i++) {
      printf("%d", x+i);
      if(i==k-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  } else {
    printf("-1\n");
  }
  return 0;
}