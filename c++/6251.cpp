#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[10000]={0, }, n, k, sum;
  cin>>n;
  while(n>0) {
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>k; sum=0; k=arr[k-1]+1;
    for(int i=0; i<n; i++) {
      if(k>arr[i]) sum+=k-arr[i];
    }
    cout<<sum<<'\n';
    cin>>n;
  }
  return 0;
}