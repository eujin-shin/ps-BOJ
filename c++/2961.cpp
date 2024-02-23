#include <iostream>
using namespace std;

int arr[10][2]={0, }, ans=-1, n;

void Backtrack(int r, int a, int b) {
  if(r==n) {
    if(a==0 && b==0) return;
    int t=(a>b ? a-b : b-a);
    if(ans<0 || t<ans) ans=t;
  } else {
    Backtrack(r+1, (a==0 ? arr[r][0] : a*arr[r][0]), b+arr[r][1]);
    Backtrack(r+1, a, b);
  }
  return;
}

int main() {
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i][0]>>arr[i][1];
  Backtrack(0, 0, 0);
  cout<<ans<<'\n';
  return 0;
}