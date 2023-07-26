#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100000] = {0, };
  int n, s, start=0, end, sum=0, len, ans=0;
  cin>>n>>s;
  for(end=0; end<n; end++) {
    cin>>arr[end];
    sum+=arr[end];
    if(sum<s) continue;
    while(sum-arr[start]>=s) {
      sum-=arr[start]; start++;
    }
    len = end-start+1;
    if(ans==0 || ans>len) {
      ans = len;
    }
  }
  cout<<ans<<'\n';
  return 0;
}