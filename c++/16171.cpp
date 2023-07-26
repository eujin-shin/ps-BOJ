#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
  queue <int> q;
  string a, b;
  int tmp, s, flag=0;
  cin>>a>>b;
  for(int i=0; i<a.size(); i++) {
    if(a[i]>='0' && a[i]<='9') continue;
    s=q.size();
    for(int j=0; j<s; j++) {
      tmp=q.front(); q.pop();
      if(b[tmp++]!=a[i]) continue;
      if(tmp==b.size()) {
        flag=1; break;
      }
      q.push(tmp);
    }
    if(flag>0) break;
    if(i<=a.size()-b.size() && a[i]==b[0]) {
      q.push(1);
      if(b.size()==1) {
        flag=1; break;
      }
    }
  }
  cout<<flag<<'\n';
  return 0;
}