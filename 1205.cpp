#include <iostream>
#include <algorithm>
using namespace std;

int arr[50]={0, };

int main() {
  int n, x, p, c=1, min=-1;
  cin>>n>>x>>p;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(arr[i]>x) c++;
    if(min<0 || min>arr[i]) min=arr[i];
  }
  if(min>=x && n==p) cout<<"-1\n";
  else cout<<c<<'\n';
  return 0;
}