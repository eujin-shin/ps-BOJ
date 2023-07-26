#include <iostream>
using namespace std;

int main() {
  bool start=true;
  int n, x, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    if(start) {
      x=tmp; start=false;
    } else if(tmp%x==0) {
      cout<<tmp<<'\n'; start=true;
    }
  }
  return 0;
}