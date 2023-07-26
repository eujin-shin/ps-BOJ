#include <iostream>
using namespace std;

int main() {
  int a, x, y, cnt;
  cin>>a;
  while(a>0) {
    cnt=1;
    for(int i=0; i<a; i++) {
      cin>>x>>y;
      cnt=cnt*x-y;
    }
    cout<<cnt<<'\n';
    cin>>a;
  }
  return 0;
}