#include <iostream>
using namespace std;

int main() {
  int n;
  long long sum=0, ans=0, tmp;
  cin>>n>>sum;
  for(int i=1; i<n; i++) {
    cin>>tmp;
    ans+=tmp*sum;
    sum+=tmp;
  }
  cout<<ans<<'\n';
  return 0;
}