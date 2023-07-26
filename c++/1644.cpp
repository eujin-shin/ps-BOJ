#include <iostream>
using namespace std;

int arr[4000001] = {0, };
int prime[2000000] = {0, };

int main() {
  int n, x = 0;
  cin>>n;
  for(int i=2; i<=n; i++) {
    if(arr[i]) continue;
    for(int j=2*i; j<=n; j+=i) {
      arr[j] = 1;
    }
  }
  for(int i=2; i<=n; i++) {
    if(arr[i]) continue;
    prime[x] = i; x++;
  }
  int start, end, sum=0, ans=0;
  for(start=0, end=0; end<x; end++) {
    sum+=prime[end];
    while(sum>n && start<end) {
      sum-=prime[start]; start++;
    }
    if(sum==n) {
      ans++;
    }
  }
  cout<<ans<<'\n';
  return 0;
}