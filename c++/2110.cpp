#include <iostream>
#define M 200000
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int arr[M]={0, };
  int c, n, left=1, right, ans=1, mid, a, b, count;
  bool flag=true;
  cin>>n>>c;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  qsort(arr, n, sizeof(int), Cmp);
  right=(arr[n-1]-arr[0])/(c-1)+1;
  while(left<=right) {
    mid=(left+right)/2;
    a=arr[0]; count=c-1;
    for(int i=1; i<n; i++) {
      b=arr[i];
      if(b-a<mid) continue;
      count--; a=b;
      if(count==0) break;
    }
    if(count>0) {
      right=mid-1;
    } else {
      ans=mid;
      left=mid+1;
    }
  }
  cout<<ans<<'\n';
  return 0;
}