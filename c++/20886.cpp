#include <iostream>
using namespace std;

int main() {
  int n, k, arr[2]={0, };
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k; arr[k]++;
  }
  cout<<"Junhee is ";
  if(arr[0]>arr[1]) cout<<"not ";
  cout<<"cute!\n";
  return 0;
}