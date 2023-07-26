#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX]={0, };
int lis[MAX]={0, };

int LowerBound(int n, int x) {
  int l=1, r=n, c, lb;
  while(l<r) {
    c=(l+r)/2;
    if(lis[c]<x) l=c+1;
    else if(lis[c]>=x) r=c;
  }
  lb=r;
  return lb;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, index=1, lb;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  lis[1]=arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i]<=lis[1]) lis[1]=arr[i];
    else if(lis[index]<arr[i]) {
      index++; lis[index]=arr[i];
    } else if(index>1) {
      lb=LowerBound(index, arr[i]);
      if(lis[lb]>arr[i]) {
        lis[lb]=arr[i];
      }
    }
  }
  cout<<index<<'\n';
  return 0;
}