#include <iostream>
#define MAX 100000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[MAX]={0, };
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  int ans=0, count=0;
  for(int i=0; i<n; i++) {
    if(arr[i]>count) {
      count++;
    } else {
      if(count>ans) ans=count;
      count=arr[i];
    }
  }
  if(count>ans) ans=count;
  cout<<ans<<'\n';
  return 0;
}