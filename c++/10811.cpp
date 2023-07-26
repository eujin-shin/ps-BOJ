#include <iostream>
using namespace std;

int arr[101]={0, };

void Reverse(int l, int r) {
  int tmp;
  while(l<r) {
    tmp=arr[l]; arr[l]=arr[r]; arr[r]=tmp;
    l++; r--;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, l, r;
  cin>>n>>m;
  for(int i=1; i<=n; i++) arr[i]=i;
  for(int i=0; i<m; i++) {
    cin>>l>>r;
    Reverse(l, r);
  }
  for(int i=1; i<=n; i++) {
    cout<<arr[i];
    if(i!=n) cout<<' ';
  }
  cout<<'\n';
  return 0;
}