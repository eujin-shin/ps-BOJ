#include <iostream>
#include <algorithm>
using namespace std;

int sum=0, sale=0, m;
int arr[1000]={0, };

void Solve(int n) {
for(int i=0; i<n; i++) {
    cin>>arr[i]; sum+=arr[i];
  }
  sort(arr, arr+n);
  for(int i=0; i<m; i++) {
    sale+=arr[n-1-i]/10;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c;
  cin>>a>>b>>c;
  m=a;
  if(m>b) m=b;
  if(m>c) m=c;
  Solve(a);
  Solve(b);
  Solve(c);
  cout<<sum<<'\n'<<sum-sale<<'\n';
  
}