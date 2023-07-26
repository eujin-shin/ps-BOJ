#include <iostream>
using namespace std;

int n, arr[10]={0, };
long long ans=-1;

void Btr(int r, int m, int x) {
  if(r==m) {
    n--;
    if(n==0) {
      long long k=1; ans=0;
      for(int i=0; i<m; i++) {
        ans+=k*arr[i]; k*=10;
      }
    }
    return;
  }
  for(int i=0; i<x; i++) {
    if(m>1 && r==0 && i==0) continue;
    arr[m-1-r]=i; Btr(r+1, m, i);
    if(n<1) return;
  }
  return;
}

int main() {
  cin>>n;
  for(int i=1; i<=10; i++) {
    Btr(0, i, 10);
    if(n==0) break;
  }
  cout<<ans<<'\n';
  return 0;
}