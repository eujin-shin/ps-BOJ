#include <iostream>
using namespace std;

int n, path[3][12]={0, };

int Len(int s, int e) {
  int min=e-s, tmp;
  for(int i=0; i<n; i++) {
    if(path[0][i]>=s && path[1][i]<=e) {
      if(path[1][i]-path[0][i]>path[2][i]) {
        tmp=Len(s, path[0][i])+Len(path[1][i], e)+path[2][i];
        if(tmp<min) min=tmp;
      }
    }
  }
  return min;
}

int main() {
  int d;
  cin>>n>>d;
  for(int i=0; i<n; i++) {
    for(int j=0; j<3; j++) cin>>path[j][i];
  }
  cout<<Len(0, d)<<'\n';
  return 0;
}