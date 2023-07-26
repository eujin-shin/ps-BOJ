#include <iostream>
using namespace std;

int energy[10]={0, };

void DFS(int n, int r, int sum, int *ans) {
  if(r==2) {
    if(sum>*ans) *ans=sum;
  } else {
    int x, left, right, count=0;
    for(int i=0; i<n; i++) {
      if(energy[i]==0) continue;
      count++;
      if(count<2 || count>=r) continue;
      left=i-1; right=i+1;
      while(energy[left]==0) {
        left--;
      }
      while(energy[right]==0) {
        right++;
      }
      x=energy[i]; energy[i]=0;
      DFS(n, r-1, energy[left]*energy[right]+sum, ans);
      energy[i]=x;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, ans=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>energy[i];
  }
  DFS(n, n, 0, &ans);
  cout<<ans<<'\n';
  return 0;
}