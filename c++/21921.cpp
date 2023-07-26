#include <iostream>
#define M 250000
using namespace std;

int arr[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, c=0, m=0, k;
  cin>>n>>x;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(i>0) arr[i]+=arr[i-1];
  }
  for(int i=x-1; i<n; i++) {
    k=arr[i];
    if(i>=x) k-=arr[i-x];
    if(k==m) c++;
    else if(k>m) {
      m=k; c=1;
    }
  }
  if(m==0) cout<<"SAD\n";
  else cout<<m<<'\n'<<c<<'\n';
  return 0;
}