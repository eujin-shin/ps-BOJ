#include <iostream>
using namespace std;

int main() {
  int c=0, max=0, a, b;
  for(int i=0; i<10; i++) {
    cin>>a>>b;
    c=c-a+b;
    if(c>max) max=c;
  }
  cout<<max<<'\n';
  return 0;
}