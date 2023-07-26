#include <iostream>
using namespace std;

int c=0;

void Btrack(int n, int r, int sum) {
  if(n==r) {
    if(sum%3==0) c++;
    return;
  }
  for(int i=0; i<3; i++) {
    if(r==0 && i==0) continue;
    Btrack(n, r+1, sum+i);
  }
  return;
}

int main() {
  int n;
  cin>>n;
  Btrack(n, 0, 0);
  cout<<c<<'\n';
  return 0;
}