#include <iostream>
using namespace std;

int heap[100001] = {0, };

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Down(int size) {
  int cur = 1, child;
  heap[1] = heap[size];
  heap[size] = 0;
  size--;
  while(cur<size) {
    child = cur*2;
    if(child<size && heap[child]<heap[child+1]) {
      child++;
    }
    if(child>size || heap[child]<heap[cur]) {
      break;
    }
    Swap(heap+cur, heap+child);
    cur = child;
  }
}

void Up(int cur) {
  while(cur>1) {
    if(heap[cur/2]>=heap[cur]) {
      break;
    } else {
      Swap(heap+cur, heap+cur/2);
      cur /= 2;
    }
  }
}

int main() {
  int n, x, size = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    if(x==0) {
      if(size==0) {
        printf("0\n");
      } else {
        printf("%d\n", heap[1]);
        Down(size);
      }
    } else {
      heap[++size] = x;
      Up(size);
    }
  }
  return 0;
}