#include <iostream>
using namespace std;

int main() {
  int arr[7]={0, }, n, k, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    k=0; arr[k]++;
    while(arr[k]>9) {
      arr[k]-=10; arr[++k]++;
    } 
    for(int j=0; j<7; j++) {
      if(arr[j]==3 || arr[j]==6 || arr[j]==9) sum++;
    }
  }
  cout<<sum<<'\n';
  return 0;
}