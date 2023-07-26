#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int main() {
  int n, k, count;
  cin>>n>>k;
  for(int i=1; i<=n; i++) q.push(i);
  cout<<"<";
  while(!q.empty()) {
    count=0;
    while(count<k-1) {
      q.push(q.front()); 
      q.pop(); count++;
    }
    cout<<q.front(); q.pop();
    if(!q.empty()) cout<<", ";
  }
  cout<<">\n";
  return 0;
}