#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  long long a, min, max, ans;
  cin>>n>>k;
  cin>>max; min=max;
  for(int i=1; i<n; i++) {
    min+=k; max-=k;
    cin>>a;
    if(i==1 || max-a>ans) ans=max-a;
    if(-min+a>ans) ans=-min+a;
    if(min>a) min=a;
    if(max<a) max=a;
  }
  cout<<ans<<'\n';
  return 0;
}