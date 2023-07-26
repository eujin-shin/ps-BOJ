#include <iostream>
#include <cstring>
using namespace std;

int arr[10]={0, }, price[50]={0, }, ans[50]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, min_idx=-1, idx, len, l, r, left;
  cin>>n>>arr[0];
  for(int i=1; i<n; i++) {
    cin>>arr[i];
    if(min_idx>0 && arr[min_idx]<arr[i]) continue; 
    min_idx=i;
  }
  cin>>m;
  len=m/arr[min_idx];
  memset(ans, min_idx, sizeof(int)*len);
  l=0; r=len-1; left=m%arr[min_idx]; idx=n-1;
  while(m>arr[0]) {
    ans[len]=0; len++; m-=arr[0];
  }
  while(m>0) {
    while(m<arr[idx]) {
      if((r-l)*(arr[min_idx]-arr[0])+m<arr[idx]) {
        if(idx<=min_idx) {
          m=0; break;
        }
        idx--; continue;
      }
      ans[r]=0; r--; 
    }
  }
}