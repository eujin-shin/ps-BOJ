#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)b-*(int *)a;
}

int main() {
  int n, sum=0;
  int price[100000] = {0, };
  cin>>n;
  for(int i=0; i<n; i++) {
    scanf("%d", &price[i]);
  }
  qsort(price, n, sizeof(int), Cmp);
  for(int i=1; i<=n; i++) {
    if(i%3) {
      sum+=price[i-1];
    }
  }
  cout<<sum<<endl;
  return 0;
}