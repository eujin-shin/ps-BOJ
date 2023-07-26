#include <iostream>
using namespace std;

int main() {
  int tmp, x, s=0;
  cin>>x;
  for(int i=0; i<5; i++) {
    cin>>tmp; if(tmp==x) s++;
  }
  cout<<s<<'\n';
  return 0;
}