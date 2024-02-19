#include <iostream>
using namespace std;

int arr[1000]={0, };

int main() {
  int n, x;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>arr[i]; arr[i]-=arr[i-1];
  }
  arr[0]=arr[n]/2;
  cout<<arr[0]<<'\n';
  for(int i=1; i<n; i++) {
    if(i%2==0) cout<<arr[i]+arr[0]<<'\n';
    else cout<<arr[i]-arr[0]<<'\n';
  }
  return 0;
}