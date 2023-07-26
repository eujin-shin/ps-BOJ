#include <iostream>
using namespace std;

int arr[101]={0, };

int main() {
  int n, m, x, y, tmp;
  cin>>n>>m;
  for(int i=1; i<=n; i++) arr[i]=i;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    tmp=arr[x]; arr[x]=arr[y]; arr[y]=tmp;
  }
  for(int i=1; i<=n; i++) {
    cout<<arr[i];
    if(i!=n) cout<<' ';
  }
  cout<<'\n';
  return 0;
}