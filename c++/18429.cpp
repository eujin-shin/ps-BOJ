#include <iostream>
using namespace std;

int arr[10]={0, };
int c=0, n, k;

void DFS(int r, int x) {
  if(r==n) {
    c++; return;
  }
  int tmp;
  x-=k;
  for(int i=0; i<n; i++) {
    if(arr[i]==0 || x+arr[i]<0) continue;
    tmp=arr[i]; arr[i]=0;
    DFS(r+1, x+tmp);
    arr[i]=tmp;
  }
  return;
}

int main() {
  cin>>n>>k;
  for(int i=0; i<n; i++) cin>>arr[i];
  DFS(0, 0);
  cout<<c<<'\n';
  return 0;
}