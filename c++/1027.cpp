#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double arr[51]={0, }, min, in;
  int n, max=0, ans=0, cnt;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>arr[i]; 
    if(max<arr[i]) max=arr[i];
  }
  for(int i=1; i<=n; i++) {
    cnt=0;
    for(int l=1; i-l>0; l++) {
      in=(arr[i-l]-arr[i])/(double)l;
      if(l==1 || min<in) {
        cnt++; min=in;
      } 
    }
    for(int r=1; i+r<=n; r++) {
      in=(arr[i+r]-arr[i])/(double)r;
      if(r==1 || min<in) {
        cnt++; min=in;
      } 
    }
    if(cnt>ans) ans=cnt;
  }
  cout<<ans<<'\n';
  return 0;
}