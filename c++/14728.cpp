#include <iostream>
using namespace std;

int arr[101][10001]={0, };
int s[101]={0, }, t[101]={0, };

int Solve(int i, int k) {
  int a, b=0;
  if(i==0) return 0;
  if(arr[i][k]>0) return arr[i][k];
  a=Solve(i-1, k);
  if(k>=t[i]) {
    b=Solve(i-1, k-t[i])+s[i];
  }
  arr[i][k]=((a>b) ? (a) : (b));
  return arr[i][k];
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>t[i]>>s[i];
  }
  cout<<Solve(n, k)<<'\n';
  return 0;
}