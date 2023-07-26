#include <iostream>
#include <stack>
#define M 1000000
using namespace std;

int arr[M]={0, }, F[M+1]={0, }, NGF[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  stack <int> s;
  int n, f, t, cur;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i]; F[arr[i]]+=1;
  }
  for(int i=n-1; i>=0; i--) {
    f=-1; cur=F[arr[i]];
    while(!s.empty()) {
      t=s.top();
      if(F[t]>cur) {
        f=t; break;
      }
      s.pop();
    }
    NGF[i]=f; s.push(arr[i]);
  }
  for(int i=0; i<n; i++) {
    cout<<NGF[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}