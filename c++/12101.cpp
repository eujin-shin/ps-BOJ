#include <iostream>
using namespace std;

int arr[12]={0, };

void init(int n) {
  for(int i=1; i<=n; i++) {
    if(i<4) arr[i]=1;
    for(int j=1; j<4; j++) {
      if(i-j<0) break;
      arr[i]+=arr[i-j];
    }
  }
  return;
}

void GetK(int n, int k) {
  int c=0;
  for(int i=1; i<4; i++) {
    if(n-i<0) break;
    c+=arr[n-i];
    if(c>=k) {
      cout<<i<<'+';
      GetK(n-i, k-c+arr[n-i]);
      return;
    }
  }
  cout<<n;
  return;
}

int main() {
  int n, k;
  cin>>n>>k;
  init(n);
  if(arr[n]<k) {
    cout<<"-1\n";
    return 0;
  }
  GetK(n, k);
  cout<<'\n';
  return 0;
}