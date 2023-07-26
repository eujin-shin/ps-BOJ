#include <iostream>
using namespace std;

int num[5000000] = {0, };


int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int n, k;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    scanf("%d", &num[i]);
  }
  qsort(num, n, sizeof(int), Cmp);
  cout<<num[k-1]<<endl;
  return 0;
}