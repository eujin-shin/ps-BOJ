#include <iostream>
using namespace std;

int arr[1000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, size=0, l=-1;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(i==0) continue;
    if(l<0 && arr[i]>arr[i-1]) l=i-1;
    else if(l>=0 && arr[i]<=arr[i-1]) {
      if(size<arr[i-1]-arr[l]) size=arr[i-1]-arr[l];
      l=-1; 
    }
  }
  if(l>0) {
    if(size<arr[n-1]-arr[l]) size=arr[n-1]-arr[l];
  } 
  cout<<size<<'\n';
  return 0;
}