#include <iostream>
#define MAX 100000
using namespace std;

typedef struct {
  int start, end;
} TIME;

int Cmp(const void *a, const void *b) {
  return ((TIME *)a)->start-((TIME *)b)->start;
}

TIME arr[MAX]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, ans=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i].start>>arr[i].end;
  }
  qsort(arr, n, sizeof(TIME), Cmp);
  int count=1, start=arr[0].start, end=arr[0].end;
  for(int i=1; i<n; i++) {
    
  }
}