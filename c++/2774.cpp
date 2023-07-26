#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int t, x, c;
  int arr[10];
  cin>>t;
  while(t--) {
    cin>>x;
    memset(arr, 0, sizeof(arr)); c=0;
    while(x>0) {
      if(arr[x%10]==0) {
        c++; arr[x%10]=1;
      }
      x/=10;
    }
    cout<<c<<'\n';
  }
  return 0;
}