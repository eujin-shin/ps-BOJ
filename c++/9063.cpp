#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, xmin, ymin, xmax, ymax;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    if(i==0) {
      xmin=xmax=x;
      ymin=ymax=y;
    }
    if(x<xmin) xmin=x;
    if(x>xmax) xmax=x;
    if(y<ymin) ymin=y;
    if(y>ymax) ymax=y;
  }
  cout<<(ymax-ymin)*(xmax-xmin)<<'\n';
  return 0;
}