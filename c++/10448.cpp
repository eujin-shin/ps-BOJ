#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[1000]={0, 1, }, x, t, k;
  cin>>t; x=1;
  while(t--) {
    cin>>k;
    while(arr[x]<k) arr[++x]=arr[x-1]+x;
    
  }
}