#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int arr[10]={0, }, w, k;
  for(int i=0; i<10; i++) cin>>arr[i];
  sort(arr, arr+10);
  w=arr[9]+arr[8]+arr[7];
  for(int i=0; i<10; i++) cin>>arr[i];
  sort(arr, arr+10);
  k=arr[9]+arr[8]+arr[7];
  cout<<w<<' '<<k<<'\n';
  return 0;
}