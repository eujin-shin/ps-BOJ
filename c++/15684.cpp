#include <iostream>
using namespace std;

int arr[11][31]={0, }, ans=-1;

int Check(int n, int h) {
  int pos[11]={0, }, tmp, cnt=0;
  for(int i=1; i<=n; i++) pos[i]=i;
  for(int i=1; i<=h; i++) {
    for(int j=1; j<n; j++) {
      if(arr[j][i]==0) continue;
      tmp=pos[j]; pos[j]=pos[j+1]; pos[j+1]=tmp;
    }
  }
  for(int i=1; i<=n; i++) if(pos[i]!=i) cnt++;
  return cnt;
}

void Track(int n, int h, int r) {
  int tmp;
  if(r>3) return;
  tmp=Check(n, h);
  if(tmp==0) ans=((ans<0 || ans>r) ? r : ans);
  else if(tmp>(3-r)*2) return;
  for(int i=1; i<n; i++) {
    for(int j=1; j<=h; j++) {
      if(arr[i][j]!=0 || arr[i-1][j]!=0 || arr[i+1][j]!=0) continue;
      arr[i][j]=1;
      Track(n, h, r+1);
      arr[i][j]=0; 
    }
    if(ans>0 && ans<=r) return;
  }
  return;
}

int main() {
  int n, m, h, a, b;
  cin>>n>>m>>h;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    arr[b][a]=1;
  }
  Track(n, h, 0);
  cout<<ans<<'\n';
  return 0;
}