#include <iostream>
using namespace std;

int main() {
  int arr[50]={0, };
  int n, l=0, r=0, cl=0, cr=0;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n; i++) {
    if(arr[i]>cl) {
      l++; cl=arr[i];
    } if(arr[n-1-i]>cr) {
      r++; cr=arr[n-1-i];
    }
  }
  cout<<l<<'\n'<<r<<'\n';
  return 0;
}