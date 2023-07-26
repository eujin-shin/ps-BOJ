#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct {
  int x, y;
} location;

int Cmp(const void *a, const void *b) {
  location f = *(location *)a, back = *(location *)b;
  if(f.y>back.y) {
    return 1;
  } else if(f.y==back.y) {
    if(f.x>back.x) {
      return 1;
    } else if(f.x==back.x) {
      return 0;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

int main() {
  location arr[100000] = {0, };
  int n, x, y;
  cin>>n;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &arr[i].x, &arr[i].y);
  }
  qsort(arr, n, sizeof(location), Cmp);
  for(int i=0; i<n; i++) {
    printf("%d %d\n", arr[i].x, arr[i].y);
  }
  return 0;
}