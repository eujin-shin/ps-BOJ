#include <iostream>
#include <vector>
using namespace std;

int arr[2][7]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, s, y, tmp, c=0;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>s>>y; arr[s][y]+=1;
  }
  for(int i=0; i<2; i++) {
    for(int j=1; j<7; j++) {
      tmp=arr[i][j]/k;
      if(k*tmp<arr[i][j]) tmp++;
      c+=tmp;
    }
  }
  cout<<c<<'\n';
  return 0;
}