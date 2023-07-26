#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin>>n; n--;
  x=n%4+1;
  if(n/4%2==1) x=6-x;
  cout<<x<<'\n';
  return 0;
}