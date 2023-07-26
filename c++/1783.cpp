#include <iostream>
using namespace std;

int main() {
  int n, m, x;
  cin>>n>>m;
  if(n==1 || m==1) x=1;
  else if(n==2) {
    x=m/2;
    if(m%2) x++;
    if(x>4) x=4;
  } else if(m<5) x=m;
  else if(m==5) x=4;
  else x=m-2;
  cout<<x<<"\n";
  return 0;
}