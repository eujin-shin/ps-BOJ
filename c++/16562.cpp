#include <iostream>
#define M 10001
using namespace std;

int s[M]={0, }, p[M]={0, };

int ReturnRoot(int x) {
  if(p[x]==x) return x;
  return p[x]=ReturnRoot(p[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, a, b, x, y, sum=0;
  cin>>n>>m>>k;
  for(int i=1; i<=n; i++) {
    cin>>s[i]; p[i]=i;
  }
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    x = ReturnRoot(a);
    y = ReturnRoot(b);
    if(s[x]<s[y]) p[y]=x;
    else p[x]=y; 
  }
  for(int i=1; i<=n; i++) {
    if(p[i]==i) sum+=s[i];
  }
  if(sum>k) cout<<"Oh no\n";
  else cout<<sum<<'\n';
  return 0;
}