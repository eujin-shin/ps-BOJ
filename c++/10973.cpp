#include <iostream>
using namespace std;

void Swap(int *a, int *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, index, a, b;
  bool notfind=true;
  int arr[10000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  for(int i=n-2; i>-1; i--) {
    if(arr[i]>arr[i+1]) {
      a=i;
      for(int j=n-1; j>i; j--) {
        if(arr[j]<arr[a]) {
          b=j; break;
        }
      }
      notfind=false;
      Swap(arr+a, arr+b);
      for(int j=1; j<=(n-a-1)/2; j++) {
        Swap(arr+n-j, arr+a+j);
      }
      break;
    }
  }
  if(notfind) cout<<"-1\n";
  else {
    for(int i=0; i<n; i++) {
      cout<<arr[i];
      if(i==n-1) cout<<'\n';
      else cout<<' ';
    }
  }
  return 0;
}