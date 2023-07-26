#include <iostream>
using namespace std;

int main() {
  int arr[50]={0, }, n, a=1, b=0, flag=1;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  if(n==1) {
    cout<<"A\n";
  } else if(n==2) {
    if(arr[0]!=arr[1]) cout<<"A\n";
    else cout<<arr[0]<<'\n';
  } else {
    if(arr[0]==arr[1]) {
      for(int i=2; i<n; i++) {
        if(arr[i]!=arr[0]) flag=0;
      }
    } else {
      if((arr[2]-arr[1])%(arr[1]-arr[0])) {
        cout<<"B\n";
        return 0;
      }
      a=(arr[2]-arr[1])/(arr[1]-arr[0]);
      b=arr[1]-a*arr[0];
      for(int i=1; i<n-1; i++) {
        if((arr[i]*a+b)!=arr[i+1]) flag=0;
      }
    }
    if(flag) cout<<arr[n-1]*a+b<<'\n';
    else cout<<"B\n";
  }
  return 0;
}