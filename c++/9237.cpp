#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, max=0;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  sort(arr, arr+n);
  for(int i=1; i<=n; i++) {
    if(i+arr[n-i]>max) max=i+arr[n-i];
  }
  cout<<max+1<<'\n';
  return 0;
}