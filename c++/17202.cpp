#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue <int> q;

int main() {
  string a, b;
  int tmp;
  cin>>a>>b;
  for(int i=0; i<8; i++) {
    q.push(a[i]-'0'); q.push(b[i]-'0');
  }
  for(int i=15; i>1; i--) {
    for(int j=0; j<i; j++) {
      tmp=q.front(); q.pop(); tmp+=q.front();
      if(tmp>9) tmp%=10;
      q.push(tmp);
    }
    q.pop();
  }
  while(!q.empty()) {
    cout<<q.front(); q.pop();
  }
  cout<<'\n';
}