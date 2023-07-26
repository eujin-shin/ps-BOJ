#include <iostream>
using namespace std;

int arr[50001][50001]={0, };

int Rascal(int n, int m) {
  if(m==0 || m==n) return arr[n][m]=1;
  if(arr[n][m]>0) return arr[n][m];
  arr[n][m]=((Rascal(n-1, m-1)*Rascal(n-1, m)+1)/Rascal(n-2, m-1));
  return arr[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m;
  cin>>t;
  while(t--) {
    cin>>n>>m;
    cout<<Rascal(n, m)<<'\n';
  }
  return 0;
}