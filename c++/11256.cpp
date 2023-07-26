#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[1000]={0, };
  int t, j, n, sum, r, c;
  cin>>t;
  while(t--) {
    cin>>j>>n;
    sum=0;
    for(int i=0; i<n; i++) {
      cin>>r>>c;
      arr[i]=r*c;
    }
    sort(arr, arr+n);
    for(int i=0; i<=n; i++) {
      if(sum>=j) {
        cout<<i<<'\n';
        break;
      }
      sum+=arr[n-i-1];
    }
  }
  return 0;
}