#include <iostream>
using namespace std;

int arr[6][1000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, max=0, ans=1;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=1; j<6; j++) {
      cin>>arr[j][i];
    }
    for(int j=0; j<i; j++) {
      for(int k=1; k<6; k++) {
        if(arr[k][j]!=arr[k][i]) continue;
        arr[0][j]++; arr[0][i]++; break;
      }
    }
  }
  for(int i=0; i<n; i++) {
    if(arr[0][i]>max) {
      max=arr[0][i]; ans=i+1;
    }
  }
  cout<<ans<<'\n';
  return 0;
}