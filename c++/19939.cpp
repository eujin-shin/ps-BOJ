#include <iostream>
using namespace std;

int main() {
  int n, k, sum=0, flag=1;
  cin>>n>>k;
  for(int i=1; i<=k; i++) {
    if(sum+i>n) {
      flag=-1; break;
    }
    sum+=i;
  }
  if(flag<0) {
    cout<<flag<<'\n';
  } else {
    if((n-sum)%(k)!=0) cout<<k<<'\n';
    else cout<<k-1<<'\n';
  }
}