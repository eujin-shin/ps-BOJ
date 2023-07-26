#include <iostream>
using namespace std;

int main() {
  int e, f, c, sum=0;
  cin>>e>>f>>c;
  e+=f;
  while(e>=c) {
    f=e/c; e%=c; sum+=f; e+=f;
  }
  cout<<sum<<'\n';
  return 0;
}