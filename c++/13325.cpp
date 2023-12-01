#include <iostream>
using namespace std;

long long sum=0;
int k, e[2500000]={0, };

int equal(int x, int d) {
  if(d==k) return e[x];
  int l, r, c;
  l=equal(x*2, d+1);
  r=equal(x*2+1, d+1);
  if(l<r) {
    c=r;
    e[x*2]+=r-l;
  } else {
    c=l;
    e[x*2+1]+=l-r;
  }
  sum+=(e[x*2]+e[x*2+1]);
  return c+e[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  int idx=2;
  cin>>k;
  for(int i=1, n=2; i<=k; i++) {
    for(int j=0; j<n; j++) {
      cin>>e[idx++];
    }
    n*=2;
  }
  equal(1, 0);
  cout<<sum<<'\n';
  return 0;
}