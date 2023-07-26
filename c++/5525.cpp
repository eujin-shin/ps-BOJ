#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int n, m, count=0, cur=0;
  char check='I';
  bool start=false;
  cin>>n>>m;
  cin>>input;
  for(int i=0; i<m; i++) {
    if(check!=input[i]) {
      if(cur>=n) {
        count+=cur-n+1;
      }
      cur=0;
      if(input[i]=='O') {
        start=false; check='I';
      } else {
        start=true; check='O';
      }
    } else {
      if(check=='I') {
        if(start) cur++;
        start=true; check='O';
      } else check='I';
    }
  }
  if(cur>=n) count+=cur-n+1;
  cout<<count<<'\n';
  return 0;
}