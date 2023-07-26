#include <iostream>
#include <stack>
#include <algorithm>
#define M 100000
using namespace std;

stack <int> s;
int arr[M]={0, }, l[M]={0, }, r[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, a, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    while(!s.empty()) {
      x=s.top();
      if(arr[x]<=arr[i]) break;
      r[x]=i-x;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()) {
    x=s.top();
    r[x]=n-x;
    s.pop();
  }
  for(int i=n-1; i>-1; i--) {
    while(!s.empty()) {
      x=s.top();
      if(arr[x]<=arr[i]) break;
      l[x]=x-i;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()) {
    x=s.top();
    l[x]=x+1;
    s.pop();
  }
  for(int i=0; i<n; i++) {
    a=arr[i]*(l[i]+r[i]-1);
    if(max<a) max=a;
  }
  cout<<max<<'\n';
  return 0;
}