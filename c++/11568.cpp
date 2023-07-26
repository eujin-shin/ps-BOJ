#include <iostream>
using namespace std;

int arr[1000][2]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, max, ans=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i][0];
    max=0;
    for(int j=i-1; j>=0; j--) {
      if(arr[j][0]<arr[i][0] && max<arr[j][1]) max=arr[j][1];
    }
    arr[i][1]=max+1;
    if(arr[i][1]>ans) ans=arr[i][1];
  }
  cout<<ans<<'\n';
  return 0;
}