#include <iostream>
using namespace std;

int main() {
  long long c[102][102] = {0, }, c2[102][102] = {0, }, stnd = 100000000000000000;
  int n, m;
  cin>>n>>m;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=i; j++) {
      if(j==0 || j==i) {
        c[i][j] = 1;
      } else {
        
        c[i][j] = c[i-1][j]+c[i-1][j-1];
        c2[i][j] = c2[i-1][j]+c2[i-1][j-1];
        if(stnd<=c[i][j]) {
          c2[i][j] = c2[i][j]+c[i][j]/stnd;
          c[i][j] = c[i][j]%stnd;
        }
      }
    }
  }
  if(c2[n][m]!=0) {
    cout<<c2[n][m];
    if(c[n][m]<stnd/10) {
      cout<<"0";
    }
  }
  cout<<c[n][m]<<endl;
  return 0;
}