#include <iostream>
using namespace std;

int num[200002] = {0, };

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void PrintNum(int size) {
  int here=1, child=2, next;
  printf("%d\n", num[1]);
  num[1]=num[size+1];
  while(here<size) {
    child=here*2;
    if(child<size && num[child]>num[child+1]) {
      child++;
    }
    if(child>size || num[here]<num[child]) {
      break;
    }
    Swap(num+here, num+child);
    here = child;
  }
}

void Sort(int size, int n) {
  int here=size, next=here/2;
  while(here>1 && num[here]<num[next]) {
    Swap(num+here, num+next);
    here=next;
    next=here/2;
  }
}

int main() {
  int n, x, size=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(x==0) {
      if(size==0) {
        printf("0\n");
      } else {
        size--;
        PrintNum(size);
      }
    } else {
      size++;
      num[size]=x;
      Sort(size, x);
    }
  }
  return 0;
}