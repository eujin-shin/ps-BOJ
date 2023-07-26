#include <iostream>
#include <vector>
#include <queue>
#define M 1000001
using namespace std;

int c[M]={0, }, p[M]={0, };

int GetDp(int n) {
  for(int i=2; i<=n; i++) {
    c[i]=c[i-1]+1; p[i]=i-1;
    if(i%2==0 && c[i/2]+1<c[i]) {
      c[i]=c[i/2]+1; p[i]=i/2;
    }
    if(i%3==0 && c[i/3]+1<c[i]) {
      c[i]=c[i/3]+1; p[i]=i/3;
    }
  }
  return c[n];
}

int main() {
  int n, cur;
  cin>>n;
  cout<<GetDp(n)<<'\n';
  cur=n;
  for(int i=0; i<=c[n]; i++) {
    cout<<cur; cur=p[cur];
    if(i!=c[n]) cout<<' ';
  }
  cout<<'\n';
  return 0;
}