#include <iostream>
using namespace std;

int arr[1001]={0, -1, };

int GetWin(int n) {
  for(int i=2; i<=n; i++) {
    arr[i]=-1;
    for(int j=1; j<=4; j++) {
      if(j>=i) break;
      if(j==2) continue;
      if(arr[i-j]==-1) {
        arr[i]=1; break;
      }
    }
  }
  return arr[n];
}

int main() {
  int n;
  cin>>n;
  if(GetWin(n)==1) cout<<"SK\n";
  else cout<<"CY\n";
  return 0;
}