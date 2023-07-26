#include <iostream>
#include <string>
using namespace std;

int main() {
  string meter;
  int x=1, ans=0, n, cur;
  cin>>meter;
  n=meter.size();
  for(int i=1; i<=n; i++) {
    cur=meter[n-i]-'0';
    if(cur>4) cur--;
    ans+=cur*x;
    x*=9;
  }
  cout<<ans<<'\n';
  return 0;
}