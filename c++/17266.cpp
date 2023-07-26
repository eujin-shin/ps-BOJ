#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, prev=0, x, tmp, max=0;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x; tmp=x-prev;
    if(i>0 && tmp%2==1) tmp=(tmp+1)/2;
    else if(i>0 && tmp%2==0) tmp=tmp/2; 
    if(tmp>max) max=tmp;
    prev=x;
  }
  if(n-prev>max) max=n-prev;
  cout<<max<<'\n';
  return 0;
}