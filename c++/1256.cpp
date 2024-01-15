#include <iostream>
using namespace std;

int c[201][201]={0, };

int main() {
  int n, m, k, a, b;
  cin>>n>>m>>k;
  c[0][0]=1;
  for(int i=1; i<=n+m; i++) {
    for(int j=0; j<=i; j++) {
      if(j==0 || j==i) c[i][j]=1;
      else if(c[i-1][j]+c[i-1][j-1]>=k || c[i-1][j]==-1 || c[i-1][j-1]==-1) c[i][j]=-1;
      else c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
  }
  if(c[n+m][m]!=-1) {
    cout<<"-1\n"; return 0;
  }
  a=n; b=m;
  for(int i=1; i<=n+m; i++) {
    if(k==0) {
      if(b>0) {
        cout<<"z"; b--;
      } else {
        cout<<"a"; a--;
      }
    } else {
      if(c[n+m-i][b]!=-1 && k>c[n+m-i][b]) {
        cout<<"z"; k-=c[n+m-i][b--];
      } else {
        cout<<"a"; a--;
      }
    } 
  }
  cout<<"\n";
  return 0;
}