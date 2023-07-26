#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int arr[101]={0, };
  int t, n, c;
  cin>>t;
  while(t--) {
    cin>>n;
    memset(arr, -1, sizeof(arr)); c=n;
    for(int i=2; i<=n; i++) {
      for(int j=i; j<=n; j+=i) {
        arr[j]=-arr[j];
        c-=arr[j];
      }
    }
    cout<<c<<'\n';
  }
  return 0;
}