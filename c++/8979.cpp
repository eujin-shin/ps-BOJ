#include <iostream>
using namespace std;

int arr[1001][3]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, x, c;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>x;
    cin>>arr[x][0]>>arr[x][1]>>arr[x][2];
  }
  c=1;
  for(int i=1; i<=n; i++) {
    if(i==k) continue;
    if(arr[i][0]>arr[k][0]) c++;
    else if(arr[i][0]<arr[k][0]) continue;
    else if(arr[i][1]>arr[k][1]) c++;
    else if(arr[i][1]<arr[k][1]) continue;
    else if(arr[i][2]>arr[k][2]) c++;
  }
  cout<<c<<'\n';
  return 0;
}