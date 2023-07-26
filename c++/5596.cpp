#include <iostream>
using namespace std;

int getp() {
  int sum=0, tmp;
  for(int i=0; i<4; i++) {
    cin>>tmp; sum+=tmp;
  }
  return sum;
}

int main() {
  int s, t;
  s=getp(); t=getp();
  if(t>s) s=t;
  cout<<s<<'\n';
  return 0;
}