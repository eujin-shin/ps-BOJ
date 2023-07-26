#include <iostream>
using namespace std;

// -39 -37 -29 -28 -6 2 11
// 78 58 12 22

int CmpMinus(const void *a, const void *b) {
  return *(int *)b-*(int *)a;
}

int CmpPlus(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int minus[50]={0, }, plus[50]={0, };
  int n, m, min=0, plu=0, temp;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>temp;
    if(temp<0) {
      minus[min] = temp; min++;
    } else {
      plus[plu] = temp; plu++;
    }
  }
  qsort(minus, min, sizeof(int), CmpMinus);
  qsort(plus, plu, sizeof(int), CmpPlus);
  int arr[50] = {0, }, index=0;
  while(min>0) {
    arr[index] = -minus[min-1];
    index++; min-=m;
  }
  while(plu>0) {
    arr[index] = plus[plu-1];
    index++; plu-=m;
  }
  int sum=0;
  qsort(arr, index, sizeof(int), CmpPlus);
  for(int i=0; i<index; i++) {
    sum+=arr[i];
    if(i!=index-1) sum+=arr[i];
  }
  cout<<sum<<'\n';
  return 0;
}