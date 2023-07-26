#include <iostream>
using namespace std;

typedef struct {
  int x, y;
} POS;

POS arr[1000000];

int Cmp(const void *a, const void *b) {
  return ((POS *)a)->x-((POS *)b)->x;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, len, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i].x>>arr[i].y;
  }
  qsort(arr, n, sizeof(POS), Cmp);
  x=arr[0].x; y=arr[0].y; len=y-x;
  for(int i=1; i<n; i++) {
    if(arr[i].x>y) {
      sum+=len; len=0; 
      x=arr[i].x; y=arr[i].y; len=y-x;
    } else if(arr[i].y>y) {
      y=arr[i].y; len=y-x;
    }
  }
  sum+=len;
  cout<<sum<<'\n';
  return 0;
}