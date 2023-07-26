#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  int arr[1001]={0, };
  int n, d, w, sum=0;
  bool s;
  priority_queue <pair<int, int> > q;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>d>>w;
    q.push(make_pair(w, d));
  }
  while(!q.empty()) {
    w = q.top().first; d = q.top().second;
    q.pop(); s = false;
    for(int i=d; i>0; i--) {
      if(arr[i]==0) {
        arr[i]=1; s=true; break;
      }
    }
    if(s) sum+=w;
  }
  cout<<sum<<'\n';
  return 0;
}