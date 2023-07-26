#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, i, c, t;
  cin>>n;
  while(n!=0) {
    i=0; c=0;
    while(n>0) {
      i++; t=n%10; n/=10;
      if(t==1) c+=2;
      else if(t==0) c+=4;
      else c+=3;
    }
    cout<<c+i+1<<'\n';
    cin>>n;
  }
  return 0;
}