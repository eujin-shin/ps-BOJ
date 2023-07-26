#include <iostream>
using namespace std;

int arr[2][101]={0, };

int main() {
  int n, m, k, x, y, s, max=0;
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    cin>>arr[0][i]>>arr[1][i];
    arr[0][i]+=arr[0][i-1];
  }
  x=0; k=1;
  for(int i=0; i<m; i++) {
    cin>>y>>s;
    y+=x;
    while(arr[0][k-1]<x) k++;
    while(arr[0][k+1]>y) {
      
    }
  }
}