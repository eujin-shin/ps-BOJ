#include <iostream>
using namespace std;

int arr[500][500]={0, };

int count(int x) {
  int cnt=0;
  while(x>0) {
    if(x%10==9) cnt++;
    x/=10;
  }
  return cnt;
}

int main() {
  int max=0, sum=0, tmp, n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    tmp=0;
    for(int j=0; j<m; j++) {
      cin>>arr[i][j];
      arr[i][j]=count(arr[i][j]);
      sum+=arr[i][j]; tmp+=arr[i][j];
    }
    if(tmp>max) max=tmp;
  }
  for(int j=0; j<m; j++) {
    tmp=0;
    for(int i=0; i<n; i++) {
      tmp+=arr[i][j];
    }
    if(max<tmp) max=tmp;
  }
  cout<<sum-max<<'\n';
  return 0;
}