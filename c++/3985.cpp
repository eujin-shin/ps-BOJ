#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int cake[1001]={0, };
  int l, n, p, k, c, e, m1=0, g, m2=0;
  cin>>l>>n;
  for(int i=1; i<=n; i++) {
    cin>>p>>k; c=0;
    if(k-p+1>m1) {
      e=i; m1=k-p+1;
    } for(int j=p; j<=k; j++) {
      if(cake[j]>0) continue;
      cake[j]=i; c+=1;
    }
    if(c>m2) {
      g=i; m2=c;
    }
  }
  cout<<e<<'\n'<<g<<'\n';
  return 0;
}