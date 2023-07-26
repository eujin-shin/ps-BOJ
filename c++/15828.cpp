#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  queue <int> q;
  int n, k;
  cin>>n>>k;
  while(k>=0) {
    if(k==0) q.pop();
    else if(q.size()<n) q.push(k);
    cin>>k;
  }
  if(q.size()==0) cout<<"empty";
  else {
    cout<<q.front(); q.pop();
  }
  while(!q.empty()) {
    cout<<' '<<q.front(); q.pop();
  }
  cout<<'\n';
  return 0;
}