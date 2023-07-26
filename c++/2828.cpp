#include <iostream>
using namespace std;

int main() {
  int n, m, j, x, l, r, sum=0;
  cin>>n>>m>>j;
  l=1; r=m;
  for(int i=0; i<j; i++) {
    cin>>x;
    if(x>=l && x<=r) continue;
    else if(x<l) {
      sum+=l-x; l=x; r=x+m-1;
    } else {
      sum+=x-r; r=x; l=x-m+1;
    }
  }
  cout<<sum<<'\n';
  return 0;
}