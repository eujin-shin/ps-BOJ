#include <iostream>
#include <stack>
using namespace std;

int arr[101][3]={0, }, m[101]={0, }, c[101]={0, };

int GetMax(int x, int n) {
  if(m[x]!=0) return m[x];
  int max=0, k=-1, t;
  for(int i=1; i<=n; i++) {
    if(arr[i][0]<arr[x][0] && arr[i][1]<arr[x][1]) {
      t=GetMax(i, n);
      if(t>max) {
        max=t; k=i;
      }
    }
  }
  c[x]=k;
  return m[x]=max+arr[x][2];
}

int main() {
  stack <int> s;
  int n, max=0, k, t;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i][0]>>arr[i][2]>>arr[i][1];
  for(int i=1; i<=n; i++) {
    t=GetMax(i, n);
    if(t>max) {
      k=i; max=t;
    }
  }
  s.push(k);
  while(c[k]!=-1) {
    s.push(c[k]);
    k=c[k];
  }
  cout<<s.size()<<'\n';
  while(!s.empty()) {
    cout<<s.top()<<'\n';
    s.pop();
  }
  return 0;
}