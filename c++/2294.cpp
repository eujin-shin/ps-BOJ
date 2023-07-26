#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int arr[10001]={0, };

void Solve(int n) {
  int x=0, tmp;
  for(int i=1; i<=n; i++) {
    while(x<v.size() && v[x]<=i) x++;
    for(int j=0; j<x; j++) {
      if(i-v[j]==0 || arr[i-v[j]]!=0) {
        tmp=arr[i-v[j]]+1;
        if(arr[i]==0 || arr[i]>tmp) arr[i]=tmp;
      }
    }
  }
  if(arr[n]==0) arr[n]=-1;
  cout<<arr[n]<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp, k;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  Solve(k);
  return 0;
}