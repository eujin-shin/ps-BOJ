#include <iostream>
using namespace std;

int main() {
  int arr[101]={0, };
  int n, m, x, y, k;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>y>>k;
    for(int j=x; j<=y; j++) arr[j]=k;
  }
  for(int i=1; i<=n; i++) {
    cout<<arr[i];
    if(i!=n) cout<<' ';
  }
  cout<<'\n';
  return 0;
}