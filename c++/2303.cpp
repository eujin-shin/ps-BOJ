#include <iostream>
using namespace std;

int arr[5]={0, }, a;

void GetMax(int r, int x, int k) {
  if(r==3) {
    if(x%10>a) a=x%10;
    return;
  }
  for(int i=k; i<5; i++) {
    GetMax(r+1, x+arr[i], i+1);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, ans, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<5; j++) cin>>arr[j];
    a=0;
    GetMax(0, 0, 0);
    if(a>=max) {
      max=a; ans=i+1;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
