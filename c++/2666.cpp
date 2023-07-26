#include <iostream>
using namespace std;

int main() {
  int n, m, l, r, x, sum=0;
  cin>>n>>l>>r>>m;
  for(int i=0; i<m; i++) {
    cin>>x;
    if(x<=l) {
      sum+=l-x; l=x;
    } else if(x>=r) {
      sum+=x-r; r=x;
    } else if(x-l<r-x) {
      sum+=x-l; l=x;
    } else {
      sum+=r-x; r=x;
    }
  }
  cout<<sum<<'\n';
  return 0;
}