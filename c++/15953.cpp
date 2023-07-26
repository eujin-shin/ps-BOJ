#include <iostream>
using namespace std;

int a[101]={0, }, b[65]={0, };

int main() {
  int arr[7]={0, 500, 300, 200, 50, 30, 10};
  int t, x, y, idx=1;
  for(int i=1; i<7; i++) {
    for(int j=0; j<i; j++) a[idx++]=arr[i];
  }
  idx=1; t=1;
  for(int i=1; i<6; t*=2, i++) {
    for(int j=0; j<t; j++) b[idx++]=512/t;
  }
  cin>>t;
  while(t--) {
    cin>>x>>y;
    cout<<(a[x]+b[y])*10000<<'\n';
  }
  return 0;
}