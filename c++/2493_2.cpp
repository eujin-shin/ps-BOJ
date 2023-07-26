#include <iostream>
#include <stack>
#define M 500000
using namespace std;

int main() {
  int arr[M]={0, }, ans[M]={0, };
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  stack <int> s;
  for(int i=0; i<n; i++) { 
    while(!s.empty() && arr[s.top()]<=arr[i]) {
      s.pop();
    }
    if(!s.empty()) ans[i]=s.top()+1;
    s.push(i);
  }
  for(int i=0; i<n; i++) {
    cout<<ans[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}