#include <iostream>
using namespace std;

int main() {
  int n, m, cnt=0;
  cin>>n>>m;
  for(int i=1; i<m; i++) {
    if(n*i%m!=0) cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}