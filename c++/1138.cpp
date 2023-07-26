#include <iostream>
#include <vector>
using namespace std;

int arr[10]={0, };
vector <int> v;

void Solve(int x) {
  arr[x]=0; v.push_back(x+1);
  for(int i=0; i<x; i++) {
    if(arr[i]==0) continue;
    else if(arr[i]==1) Solve(i);
    else arr[i]-=1;
  }
  return;
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(arr[i]==0) Solve(i);
  }
  for(int i=0; i<n; i++) {
    cout<<v[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}