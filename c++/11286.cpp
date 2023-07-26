#include <iostream>
#define M 100001
using namespace std;

int h[M]={0, };

void Swap(int *a, int *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

void Up() {
  int cur=h[0];
  while(cur>1) {
    if(abs(h[cur/2])>abs(h[cur]) || (abs(h[cur/2])==abs(h[cur]) && h[cur]<h[cur/2])) {
      Swap(h+cur, h+(cur/2));
      cur/=2;
    } else break;
  }
  return;
}

void Down() {
  int k=h[0], cur=1, l, r, next;
  while(cur<k) {
    next=-1;
    l=cur*2; r=l+1;
    if(l<=k) {
      next=l;
      if(r<=k) {
        if(abs(h[r])<abs(h[l])) next=r;
        else if(abs(h[r])==abs(h[l]) && h[r]<h[l]) next=r;
      }
    }
    if(next>0) {
      if(abs(h[next])<abs(h[cur]) || (abs(h[next])==abs(h[cur]) && h[next]<h[cur])) {
        Swap(h+next, h+cur);
        cur=next;
      } else break;
    }
  }
  return;
}

int main() {
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    if(x==0) {
      if(h[0]==0) printf("0\n");
      else {
        printf("%d\n", h[1]);
        h[1]=h[h[0]];
        h[0]=h[0]-1;
        Down();
      }
    } else {
      h[0]=h[0]+1;
      h[h[0]]=x;
      Up();
    }
  }
  return 0;
}