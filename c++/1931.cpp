#include <iostream>
using namespace std;

typedef struct {
  int start, end;
} Time;

int Cmp(const void *a, const void *b) {
  Time x = *(Time *)a, y = *(Time *)b;
  int ret = -1;
  if(x.start>y.start) {
    ret = 1;
  } else if(x.start==y.start) {
    if(x.end>y.end) {
      ret = 1;
    } else if(x.end==y.end) {
      ret = 0;
    }
  } 
  return ret;
}

int main() {
  int n, end, count = 1;
  Time arr[100001] = {0, };
  cin>>n;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &arr[i].start, &arr[i].end);
  }
  qsort(arr, n, sizeof(Time), Cmp);
  end = arr[0].end;
  for(int i=1; i<n; i++) {
    if(arr[i].end<end) {
      end = arr[i].end;
    } else if(arr[i].start>=end) {
      count++;
      end = arr[i].end;
    }
  }
  cout<<count<<endl;
  return 0;
}